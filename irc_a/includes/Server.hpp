#pragma once

#include <iostream>
#include <exception>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <sys/event.h>
#include <map>
#include <fcntl.h>

#include "User.hpp"
#include "Command.hpp"
#include "Channel.hpp"

#define ADD 1
#define DELETE 0

#define QUIT 1

#define MAX_EVENTS 10
#define MAX_BUFFER_SIZE 1024
#define MAX_USER 10

class Server
{
private:
    int _port;
    int _password;
    int _serverSocket;
    int _kq;
    int _userCount;

    std::vector<User*> _users;
    std::vector<Channel*> _channels;
    std::map<int, std::string> _buffers;

    void createServerSocket();
    void bindServerSocket();
    void listenServerSocket();
    void createKqueue();
    void addServerSocketToKqueue();
    void acceptClientSocket();

    int recvFromClient(int clientSocket);

    void changeEvent(int clientSocket, int flag);

    Server();
public:
    Server(int ac, char **av);
    ~Server();

    void run();

    class ServerError : public std::exception
    {
    private:
        const char* _msg;
    public:
        ServerError(const char* msg) : _msg(msg) {}
        const char* what() const throw() { return _msg; }
    };
};
