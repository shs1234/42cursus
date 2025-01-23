#include "Server.hpp"

Server::Server(int ac, char **av) : _userCount(0)
{
	if (ac != 3)
		throw ServerError("Usage: ./server <port> <password>");
	for (int i = 0; av[1][i]; i++)
	{
		if (!std::isdigit(av[1][i]))
			throw ServerError("Port must be a number");
		if (i == 5)
			throw ServerError("Port must be between 0 and 65535");
	}
	for (int i = 0; av[2][i]; i++)
	{
		if (!std::isdigit(av[2][i]))
			throw ServerError("Password must be a number");
		if ((av[2][i + 1] == '\0' && i < 3) || i == 4)
			throw ServerError("Password is positive integer between 1000 and 9999");
	}
	std::stringstream stream1(av[1]);
	stream1 >> _port;
	std::stringstream stream2(av[2]);
	stream2 >> _password;
	if (_port < 0 || _port > 65535)
		throw ServerError("Port must be between 0 and 65535");
	std::cout << "Server created" << std::endl;
}

Server::~Server()
{
	std::cout << "Server destroyed" << std::endl;
	close(_serverSocket);
	close(_kq);
	for (size_t i = 0; i < _users.size(); i++)
		delete _users[i];
	for (size_t i = 0; i < _channels.size(); i++)
		delete _channels[i];
}

void Server::run()
{
	createServerSocket(); 		// 1. 소켓 생성
	bindServerSocket(); 		// 2. 소켓에 IP 주소와 포트 할당
	listenServerSocket(); 		// 3. 연결 대기 상태로 설정

	createKqueue(); 			// kqueue 인스턴스 생성
	addServerSocketToKqueue(); 	// 서버 소켓을 kqueue에 등록

	while (true)
	{
		struct kevent eventList[MAX_EVENTS]; // 최대 MAX_EVENTS개의 이벤트까지 처리
		int num_events = kevent(_kq, NULL, 0, eventList, MAX_EVENTS, NULL);
		if (num_events == -1)
		{
			std::cerr << "Error in kevent" << std::endl;
			break;
		}
		std::cout << "------------------[recv]------------------" << std::endl;
		std::cout << "num_events : " << num_events << std::endl;
		for (int i = 0; i < num_events; i++)
		{
			int socket = eventList[i].ident;
			if (socket == _serverSocket)
			{
				// 클라이언트 소켓을 kqueue에 추가
				acceptClientSocket();
			}
			else
			{
				if (eventList[i].flags & EV_EOF) // 클라이언트 소켓이 연결을 끊었을 때
				{
					// user 삭제
					Command cmd(socket, _buffers[socket], _users, _channels, _password);
					cmd.quit();
					// 클라이언트 소켓을 kqueue에서 제거
					changeEvent(socket, DELETE);
					continue;
				}
				if (recvFromClient(socket))
				{
					Command cmd(socket, _buffers[socket], _users, _channels, _password);
					std::cout << _buffers[socket] << std::endl;
					_buffers[socket].clear();
					if (cmd.exec() == QUIT)
						changeEvent(socket, DELETE);
				}
			}
		}
	}
}

void Server::createServerSocket()
{
	_serverSocket = socket(AF_INET, SOCK_STREAM, 0); 	// AF_INET : IPv4, SOCK_STREAM : TCP
	if (_serverSocket == -1)
		throw ServerError("Error creating socket");
	fcntl(_serverSocket, F_SETFL, O_NONBLOCK);
}
void Server::bindServerSocket()
{
	sockaddr_in serverAddress;
	std::memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;  				// IPv4
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); 	// INADDR_ANY : 자동으로 이 컴퓨터에 존재하는 랜카드 중 사용가능한 랜카드의 IP주소를 사용하라는 의미
	serverAddress.sin_port = htons(_port); 				// 호스트 바이트 순서를 네트워크 바이트 순서로 변환

	if (bind(_serverSocket, reinterpret_cast<struct sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1)
	{
		close(_serverSocket);
		throw ServerError("Error binding socket");
	}
}
void Server::listenServerSocket()
{
	if (listen(_serverSocket, 5) == -1) 	// 최대 5개의 연결을 대기열에 둠
	{
		close(_serverSocket);
		throw ServerError("Error listening on socket");
	}
	std::cout << "Server is listening on port " << _port << "..." << std::endl;
}
void Server::createKqueue()
{
	_kq = kqueue();
	if (_kq == -1)
	{
		close(_serverSocket);
		throw ServerError("Error creating kqueue instance");
	}
}
void Server::addServerSocketToKqueue()
{
	struct kevent event;
	// EVFILT_READ : 읽기 가능한 상태
	EV_SET(&event, _serverSocket, EVFILT_READ, EV_ADD, 0, 0, NULL);
	if (kevent(_kq, &event, 1, NULL, 0, NULL) == -1)
	{
		close(_serverSocket);
		close(_kq);
		throw ServerError("Error adding server socket to kqueue");
	}
}
void Server::acceptClientSocket()
{
	sockaddr_in clientAddress;
	socklen_t clientAddressLength = sizeof(clientAddress);
	int clientSocket = accept(_serverSocket, reinterpret_cast<struct sockaddr*>(&clientAddress), &clientAddressLength);
	std::cout << clientSocket << std::endl;
	if (_userCount >= MAX_USER)
	{
		std::cout << "User limit reached" << std::endl;
		close(clientSocket);
		return;
	}
	if (clientSocket == -1)
	{
		close(_serverSocket);
		close(_kq);
		throw ServerError("Error accepting client connection");
	}
	fcntl(clientSocket, F_SETFL, O_NONBLOCK);
	changeEvent(clientSocket, ADD);
	std::cout << "Client connected" << std::endl;
}

int Server::recvFromClient(int socket)
{
	// 클라이언트로부터 데이터를 받음
	char buffer[MAX_BUFFER_SIZE];
	ssize_t bytesRead;
	do
	{
		bytesRead = recv(socket, buffer, sizeof(buffer), 0);
		if (bytesRead == -1)
		{
			std::cerr << "Error reading from client socket" << std::endl;
			return 0;
		}
		_buffers[socket] += std::string(buffer, bytesRead);
		std::cout << "buffer : " << _buffers[socket] << std::endl;
	} while (bytesRead == sizeof(buffer));
	if (_buffers[socket].size() > 512)
	{
		std::cerr << "Error: Message too long" << std::endl;
		_buffers[socket].clear();
		return 0;
	}
	if (_buffers[socket][_buffers[socket].size() - 1] != '\n')
		return 0;
	std::cout << "final buffer : " << _buffers[socket] << std::endl;
	return 1;
}

void Server::changeEvent(int socket, int flag)
{
	struct kevent event;
	if (flag)
	{
		EV_SET(&event, socket, EVFILT_READ, EV_ADD, 0, 0, NULL);
		if (kevent(_kq, &event, 1, NULL, 0, NULL) == -1)
		{
			close(socket);
			throw ServerError("Error adding client socket to kqueue");
		}
		_userCount++;
	}
	else
	{
		struct kevent changeEvent;
		EV_SET(&changeEvent, socket, EVFILT_READ, EV_DELETE, 0, 0, NULL);
		if (kevent(_kq, &changeEvent, 1, NULL, 0, NULL) == -1)
		{
			close(socket);
			throw ServerError("Error deleting client socket from kqueue");
		}
		_buffers.erase(socket);
		close(socket);
		_userCount--;
	}
}
