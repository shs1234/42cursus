#include "Command.hpp"

Command::Command(int clientSocket, std::string msg, std::vector<User*> &us, std::vector<Channel*> &ch, int password) 
: _clientSocket(clientSocket),
_msg(msg),
_users(us),
_channels(ch),
_password(password)
{
}

Command::~Command()
{
}

// 제대로 파싱되었는지 확인용
void Command::printparsing()
{
    std::cout << "                  [parsing]              " << std::endl;
    std::cout << "_prefix : " << _prefix << std::endl;
    std::cout << "_command : " << _command << std::endl;
    for (size_t i = 0; i < _params.size(); i++)
        std::cout << "_params[" << i << "] : " << _params[i] << std::endl;
}

void Command::parseMessage()
{
    size_t position = 0;
    
    if (_msg[0] == ':') 
    {
        position = _msg.find(' ');
        _prefix = _msg.substr(1, position - 1);
        position++;
    }
    size_t nextSpace = _msg.find(' ', position);
    _command = _msg.substr(position, nextSpace - position);
    while (nextSpace != std::string::npos) 
    {
        position = nextSpace + 1;
        if (_msg[position] == ':') 
        {
            std::string temp = _msg.substr(position + 1);
            if (temp.length() > 0)
                _params.push_back(temp);
            break;
        } 
        else 
        {
            nextSpace = _msg.find(' ', position);
            std::string temp = _msg.substr(position, nextSpace - position);
            if (temp.length() > 0)
                _params.push_back(temp);
        }
    }
}

// 명령어 실행
int Command::exec()
{
    std::istringstream stream(_msg);
    std::string command;
    int result = 0;

    // 공백 문자를 기준으로 문자열을 분리하고 벡터에 저장
    while (std::getline(stream, command, '\n'))
    {
        Commands com;
        if (command[command.length() - 1] == '\r')
            command.erase(command.length() - 1, 1);
        _msg = command;
        parseMessage();
        com._prefix = _prefix;
        com._command = _command;
        com._params = _params;
        _commands.push_back(com);
        _params.clear();
    }
    
    for (size_t i = 0; i < _commands.size(); i++)
    {
        _prefix = _commands[i]._prefix;
        _command = _commands[i]._command;
        _params = _commands[i]._params;
        printparsing();
        if (_command == "PASS")
            result = pass();
        else if (_command == "NICK")
            result = nick();
        else if (_command == "USER")
            result = user();
        if (_command == "JOIN")
            join();
        else if (_command == "PART")
            part();
        else if (_command == "MODE")
            mode();
        else if (_command == "TOPIC")
            topic();
        else if (_command == "INVITE")
            invite();
        else if (_command == "KICK")
            kick();
        else if (_command == "PRIVMSG")
            privmsg();
        else if (_command == "PING")
            ping();
        else if (_command == "QUIT")
        {
            quit();
            return 1;
        }
        else if (_command == "CAP")
        {
            std::string cap_msg = "Please login with prefix -nocap...";
            cap_msg += CRFL;
            send(_clientSocket, cap_msg.c_str(), cap_msg.length(), 0);
            result = 1;
            break;
        }
        else
            std::cout << "Command not found" << std::endl;

        std::cout << "                  [send]              " << std::endl;
        if (_response.size() > 0)
        {
            std::cout << _response << std::endl;
            send(_clientSocket, _response.c_str(), _response.length(), 0);
        }
        _prefix.clear();
        _command.clear();
        _params.clear();
        _response.clear();
        if (result == 1)
            break;
    }
    // 확인용
    std::cout << "                  [users]              " << std::endl;
    for (size_t i = 0; i < _channels.size(); i++)
    {
        std::cout << "channel : " << _channels[i]->getName() << std::endl;
        for (size_t j = 0; j < _channels[i]->getOperators().size(); j++)
        {
            std::cout << "operator : " << _channels[i]->getOperators()[j]->getNickname() << std::endl;
        }
        for (size_t j = 0; j < _channels[i]->getMembers().size(); j++)
        {
            std::cout << "member : " << _channels[i]->getMembers()[j]->getNickname() << std::endl;
        }
    }
    return 0;
}

void Command::ping()
{
    _response += ":irc.server.com PONG irc.server.com :";
    _response += _params[0];
    _response += CRFL;
}

// ERR_NEEDMOREPARAMS ERR_ALREADYREGISTRED ERR_PASSWDMISMATCH
int Command::pass()
{
    if (_params.size() == 0)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 client PASS :Not enough parameters";
        _response += CRFL;
        return 1;
    }
    User *user = findUser(_clientSocket);
    if (user && user->getPass() == true)
    {
        // ERR_ALREADYREGISTRED
        _response += ":irc.server.com 462 ";
        if (user->getNickname() != "")
            _response += user->getNickname();
        else
            _response += "client";
        _response += " :You may not reregister";
        _response += CRFL;
        return 0;
    }
    std::stringstream ss;
    ss << _password;
    if (ss.str() != _params[0])
    {
        // ERR_PASSWDMISMATCH
        _response += ":irc.server.com 464 client :Password incorrect";
        _response += CRFL;
        return 1;
    }
    User *newUser = new User();
    newUser->setClientSocket(_clientSocket);
    _users.push_back(newUser);
    newUser->setPass(true);
    std::cout << "pass" << std::endl;
    return 0;
}
int Command::nick()
{
    User *user = findUser(_clientSocket);
    if (user == NULL)
        return 1;

    std::string clientnick = user->getNickname();
    if (clientnick == "")
        clientnick = "client";

    if (_params.size() == 0)
    {
        // ERR_NONICKNAMEGIVEN
        _response += ":irc.server.com 431 ";
        _response += clientnick;
        _response += " :No nickname given";
        _response += CRFL;
        return 1;
    }
    for (size_t i = 0; i < _users.size(); i++)
    {
        if (_users[i]->getNickname() == _params[0] && _users[i]->getRealname() != "")
        {
            // ERR_NICKNAMEINUSE
            _response += ":irc.server.com 433 ";
            _response += clientnick;
            _response += " ";
            _response += _params[0];
            _response += " :Nickname is already in use";
            _response += CRFL;
            return 0;
        }
    }

    for (size_t i = 0; i < _params[0].size(); i++)
    {
        // ERR_ERRONEUSNICKNAME
        if (_params[0][i] == '#' || _params[0][i] == '&' || _params[0][i] == ':' || std::isspace(static_cast<unsigned char>(_params[0][i])))
        {
            if (user->getNick() == false)
                eraseUser(_clientSocket);
            _response += ":irc.server.com 432 ";
            _response += clientnick;
            _response += " ";
            _response += _params[0];
            _response += " :Erroneus nickname";
            _response += CRFL;
            return 1;
        }
    }

    if (clientnick != "client" && user->getNickname() != _params[0])
    {
        _response += ":";
        _response += user->getNickUserHost();
        _response += " NICK :";
        _response += _params[0];
        _response += CRFL;
    }

    user->setNickname(_params[0]);
    user->setNick(true);
    welcomeMsg();
    std::cout << "nick" << std::endl;
    return 0;
}
int Command::user()
{
    User *user = findUser(_clientSocket);
    if (user == NULL)
        return 1;
    if (_params.size() < 4)
    {
        // ERR_NEEDMOREPARAMS
        eraseUser(_clientSocket);
        _response += ":irc.server.com 461 client USER :Not enough parameters";
        _response += CRFL;
        return 1;
    }
    if (user->getUser() == true)
    {
        // ERR_ALREADYREGISTRED
        eraseUser(_clientSocket);
        _response += ":irc.server.com 462 ";
        _response += user->getNickname();
        _response += " :You may not reregister";
        _response += CRFL;
        return 1;
    }
    user->setUsername(_params[0]);
    user->setHostname(_params[1]);
    user->setServername(_params[2]);
    user->setRealname(_params[3]);
    user->setUser(true);
    welcomeMsg();
    std::cout << "user" << std::endl;
    return 0;
}

void Command::welcomeMsg()
{
    User *user = findUser(_clientSocket);
    std::string response;
    if (user->getWelcome() == false && user->getPass() == true && user->getNick() == true && user->getUser() == true)
    {
        response += ":irc.server.com 001 ";
        response += user->getNickname();
        response += " :Welcome to the IRC Network ";
        response += user->getNickUserHost();
        response += CRFL;
        response += ":irc.server.com 002 ";
        response += user->getNickname();
        response += " :Your host is irc.server.com, running version 1.0.0";
        response += CRFL;
        response += ":irc.server.com 003 ";
        response += user->getNickname();
        response += " :This server was created Sat Jan 20 2024 at 20:28:37 KST";
        response += CRFL;
        response += ":irc.server.com 004 ";
        response += user->getNickname();
        response += " irc.server.com 1.0.0 i itkol :kol";
        response += CRFL;
        send(_clientSocket, response.c_str(), response.length(), 0);
        user->setWelcome(true);
    }
}

// 예시
// 고양이->서버: JOIN #test
// 서버->고양이: :root_!root@127.0.0.1 JOIN :#test
// :irc.local 353 root_ = #test :@root root_               <- names 명령어
// :irc.local 366 root_ #test :End of /NAMES list.
// 서버->강아지: :root_!root@127.0.0.1 JOIN :#test
// 353     RPL_NAMREPLY
//                 "<channel> :[[@|+]<nick> [[@|+]<nick> [...]]]"
// 366     RPL_ENDOFNAMES
//                 "<channel> :End of /NAMES list"
void Command::join()
{

    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    User *user = findUser(_clientSocket);
    if (_params.size() < 1)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += user->getNickname();
        _response += " JOIN :Not enough parameters";
        _response += CRFL;
        return ;
    }


    std::string response_me;
    std::string response_other;
    response_me = ":" + user->getNickUserHost() + " JOIN :" + _params[0] + CRFL;
    response_other = response_me;
    bool exist = false;

    // 채널이 이미 존재하면 멤버로 추가
    for (size_t i = 0; i < _channels.size(); i++)
    {
        if (_channels[i]->getName() == _params[0])
        {
            exist = true;
            if (_channels[i]->getMode(CH_MODE_I) && user->getInvitation(_params[0]) == NULL)
            {
                _response += ":irc.server.com 473 ";
                _response += user->getNickname();
                _response += " ";
                _response += _channels[i]->getName();
                _response += " :Cannot join channel (invite only)";
                _response += CRFL;
                return ;
            }
            if (_channels[i]->getMode(CH_MODE_K) && (_params.size() <= 1 || (_params.size() > 1 && _channels[i]->getPw() != _params[1])))
            {
                if (!(_channels[i]->getMode(CH_MODE_I) && findUser(_clientSocket)->getInvitation(_params[0]) != NULL))
                {
                    _response += ":irc.server.com 475 ";
                    _response += findUser(_clientSocket)->getNickname();
                    _response += " ";
                    _response += _channels[i]->getName();
                    _response += " :Cannot join channel (incorrect channel key)";
                    _response += CRFL;
                    return ;
                }
            }
            if (_channels[i]->getMode(CH_MODE_L) && _channels[i]->getUserlimit() <= _channels[i]->getUsercount())
            {
                _response += ":irc.server.com 471 ";
                _response += user->getNickname();
                _response += " ";
                _response += _channels[i]->getName();
                _response += " :Cannot join channel (channel is full)";
                _response += CRFL;
                return ;
            }
            _channels[i]->addMember(user);
            user->addChannel(_channels[i]);
            if (_channels[i]->getMode(CH_MODE_I))
                user->removeInvitation(_channels[i]);
            break;
        }
    }
    // 채널이 없으면 새로 생성하고 오퍼레이터로 추가
    if (!exist)
    {
        if (_params[0][0] != '#')
        {
            _response += "Please put # on channel's name";
            _response += CRFL;
            return ;
        }
        Channel *channel = new Channel();
        channel->setName(_params[0]);
        channel->addOperator(user);
        user->addChannel(channel);
        _channels.push_back(channel);
    }

    // 채널에 있는 멤버들에게 JOIN 메시지 전송
    response_me += names(_params[0]); // 353, 366
    Channel *channel = findChannel(_params[0]);
    channel->sendtoAllButOne(response_other, user);
    send(_clientSocket, response_me.c_str(), response_me.length(), 0);
}

// 예시
// 다람쥐->서버: PRIVMSG #test :qqqqqqqqqqqqq
// 서버->강아지: :root__!root@127.0.0.1 PRIVMSG #test :qqqqqqqqqqqqq
// 서버->고양이: :root__!root@127.0.0.1 PRIVMSG #test :qqqqqqqqqqqqq
// ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
// ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
// ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
// ERR_NOSUCHNICK
void Command::privmsg()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    std::string message;
    User *me = findUser(_clientSocket);
    if (_params.size() < 2)
    {
        _response += ":irc.server.com 461 ";
        _response += me->getNickname();
        _response += " PRIVMSG :Not enough parameters";
        _response += CRFL;
        return ;
    }
    if (_params[0] == "")
    {
        _response += ":irc.server.com 411 ";
        _response += me->getNickname();
        _response += " :No recipient given PRIVMSG";
        _response += CRFL;
        return ;
    }
    else if (_params[1] == "")
    {
        _response += ":irc.server.com 412 ";
        _response += me->getNickname();
        _response += " :No text to send";
        _response += CRFL;
        return ;
    }

    User *user = findUser(_params[0]);
    Channel *channel = findChannel(_params[0]);
    if (user == NULL)
    {
        if (channel == NULL)
        {
            _response += ":irc.server.com 401 ";
            _response += me->getNickname();
            _response += " ";
            _response += _params[1];
            _response += " :No such nick/channel";
            _response += CRFL;
            return ;
        }
        else
        {
            message = ":" + me->getNickUserHost() + " " + _command + " " + _params[0] + " :" + _params[1] + CRFL;
            for (size_t i = 0; i < channel->getOperators().size(); i++)
            {
                if (channel->getOperators()[i]->getClientSocket() != _clientSocket)
                    send(channel->getOperators()[i]->getClientSocket(), message.c_str(), message.length(), 0);
            }
            for (size_t i = 0; i < channel->getMembers().size(); i++)
            {
                if (channel->getMembers()[i]->getClientSocket() != _clientSocket)
                    send(channel->getMembers()[i]->getClientSocket(), message.c_str(), message.length(), 0);
            }
        }
    }
    else
    {
        message = ":" + me->getNickUserHost() + " " + _command + " " + _params[0] + " :" + _params[1] + CRFL;
        send(user->getClientSocket(), message.c_str(), message.length(), 0);
    }
}

// ERR_NEEDMOREPARAMS
// ERR_NOSUCHCHANNEL
// ERR_NOTONCHANNEL
void Command::part()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    User *user = findUser(_clientSocket);
    if (_params.size() == 0)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += user->getNickname();
        _response += " PART :Not enough parameters";
        _response += CRFL;
        return ;
    }
    
    // 문자열 스트림을 comma 기준으로 분할하여 벡터에 저장
    std::vector<std::string> params_comma;
    std::stringstream ss(paramsJoin());
    std::string item;
    while (std::getline(ss, item, ','))
        params_comma.push_back(item);

    // response 생성
    std::string response;
    for (size_t i = 0; i < params_comma.size(); i++)
    {
        response.clear();
        Channel *channel = findChannel(params_comma[i]);
        if (channel)
        {
            // 이 채널에 유저가 소속되어 있는지 확인.
            if (channel->isMember(user) || channel->isOperator(user))
            {
                response += ":" + user->getNickUserHost() + " PART :" + params_comma[i] + CRFL;
                channel->sendToAll(response);
                user->partChannel(channel);
                if (channel->getUsercount() == 0)
                    eraseChannel(channel);
                continue;
            }
            else // ERR_NOTONCHANNEL
                response += ":irc.local 442 " + user->getNickname() + " " + params_comma[i] + " :You're not on that channel" + CRFL;
        }
        else // ERR_NOSUCHCHANNEL
            response += ":irc.local 403 " + user->getNickname() + " " + params_comma[i] + " :No such channel" + CRFL;
        send(_clientSocket, response.c_str(), response.length(), 0);
    }
}

void Command::mode()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    User *me = findUser(_clientSocket);
    if (_params.size() < 1)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += me->getNickname();
        _response += " MODE :Not enough parameters";
        _response += CRFL;
        return ;
    }
    size_t p_size = _params.size();

    if (_params[0][0] == '#')   // 채널 mode 변경
    {
        Channel *ch = findChannel(_params[0]);
        std::string modetype = "itkol";
        if (ch == NULL)
        {
            _response += ":irc.server.com 403 ";
            _response += me->getNickname();
            _response += " ";
            _response += _params[0];
            _response += " :No such channel";
            _response += CRFL;
            return ;
        }

        if (p_size == 1)
        {
            // RESPONSE 324
            // 채널 모드 조회
            bool pw_open = (ch->isMember(me) || ch->isOperator(me)) ? true : false;
            _response += ":irc.server.com 324 ";
            _response += me->getNickname();
            _response += " ";
            _response += _params[0];
            _response += " +";
            for (int i = 0; i < CH_MODES; i++)
            {
                if (ch->getMode(i))
                    _response += modetype[i];
            }
            
            if (ch->getMode(CH_MODE_K) && ch->getMode(CH_MODE_L))
            {
                _response += " ";
                if (pw_open)
                    _response += ch->getPw();
                else
                    _response += "???";
                _response += " :";
                std::ostringstream ss;
                ss << ch->getUserlimit();
                _response += ss.str();
            }
            else if (ch->getMode(CH_MODE_K))
            {
                _response += " :";
                if (pw_open)
                    _response += ch->getPw();
                else
                    _response += "???";
            }
            else if (ch->getMode(CH_MODE_L))
            {
                _response += " :";
                std::ostringstream ss;
                ss << ch->getUserlimit();
                _response += ss.str();
            }
            _response += CRFL;
        }
        else
        {
            // 파싱을 통해 부호와 모드를 확인한다.
            // +, -는 클라이언트에서 알아서 1차로 정리해서 주기 때문에, _param[1][0]이 부호인지만 확인한다.
            // 반복문을 통해 해당하는 모드 명령어를 하나씩 처리한다.
            // 만약 없는 모드라면 ERR_UNKNOWNMODE (472)
            size_t pi_size;
            bool is_mode = true, mark = true;
            std::string mode_msg = " ";
            std::vector<std::string> mode_for_key;
            std::string middle_mode_msg = "";
            std::string last_mode_msg = "";
            int mode_key_count = 0;

            //채널장이 아닐 경우
            //ERR_CHANOPRIVSNEEDED
            if (ch->isOperator(me) == false)
            {
                _response += ":irc.server.com 482 ";
                _response += me->getNickname();
                _response += " ";
                _response += ch->getName();
                _response += " :You must have channel op access or above to set channel mode";
                _response += CRFL;
                return ;
            }

            for (size_t i = 1; i < p_size; i++)
            {
                // 모드에 대한 변경사항을 먼저 받고, 인자가 필요하면 인자를 받는 모드로 바꾼다.
                if (is_mode)
                {
                    pi_size = _params[i].size();
                    mark = true;
                    for (size_t j = 0; j < pi_size; j++)
                    {
                        if (_params[i][j] == '-')
                            mark = false;
                        else if (_params[i][j] == '+')
                            mark = true;
                        else
                        {
                            if (_params[i][j] == 'i' || _params[i][j] == 't' || _params[i][j] == 'k' || _params[i][j] == 'o' || _params[i][j] == 'l')
                            {
                                // 권한이 변경되는지 확인
                                // 전에 이 모드에 대해 적용한 부분이 있는지 확인 ex) +i +t +i
                                // response로 보낼 문자열 준비
                                // 권한 바꾸기
                                // 인자 없이 실행되는거는 하고 인자 있는거는 인자 검사 후 하기
                                if (_params[i][j] == 'o' || _params[i][j] == 'k' || (_params[i][j] == 'l' && mark == true))
                                {
                                    is_mode = false;
                                    if (_params[i][j] == 'o' && mark == false)
                                        mode_for_key.push_back("-o");
                                    else if (_params[i][j] == 'o' && mark == true)
                                        mode_for_key.push_back("+o");
                                    else if (_params[i][j] == 'k' && mark == true)
                                        mode_for_key.push_back("+k");
                                    else if (_params[i][j] == 'k' && mark == false)
                                        mode_for_key.push_back("-k");
                                    else if (_params[i][j] == 'l' && mark == true)
                                        mode_for_key.push_back("+l");
                                    mode_key_count++;
                                }
                                else
                                {
                                    int mode_index = -1;
                                    if (_params[i][j] == 'i')
                                        mode_index = CH_MODE_I;
                                    else if (_params[i][j] == 't')
                                        mode_index = CH_MODE_T;
                                    else
                                        mode_index = CH_MODE_K;
                                    if ((ch->getMode(mode_index) == false && mark == true) || (ch->getMode(mode_index) == true && mark == false))
                                    {
                                        if (mark == true) mode_msg += "+";
                                        else mode_msg += "-";
                                        mode_msg += modetype[mode_index];
                                        ch->setMode(mode_index, mark);
                                    }
                                }
                            }
                            else
                            {
                                // ERR_UNKNOWNMODE (472)
                                _response += ":irc.server.com 472 ";
                                _response += me->getNickname();
                                _response += " ";
                                _response += _params[i][j];
                                _response += " :is not a recognised channel mode.";
                                _response += CRFL;
                            }
                        }
                    }
                }
                else
                {
                    //인자 받아주기 - +k, -k, +o, -o, +l
                    if (mode_for_key[0] == "+k")
                    {
                        if (ch->getMode(CH_MODE_K) == false)
                        {
                            ch->setPw(_params[i]);

                            mode_msg += "+k";
                            if (last_mode_msg != "")
                            {
                                middle_mode_msg += last_mode_msg;
                                middle_mode_msg += " ";
                            }
                            last_mode_msg = _params[i];
                            ch->setMode(CH_MODE_K, mark);
                        }
                    }
                    else if (mode_for_key[0] == "-k")
                    {
                        if (ch -> getMode(CH_MODE_K) == true)
                        {
                            if (ch->getPw() == _params[i])
                            {
                                ch->setPw("");

                                mode_msg += "-k";
                                if (last_mode_msg != "")
                                {
                                    middle_mode_msg += last_mode_msg;
                                    middle_mode_msg += " ";
                                }
                                last_mode_msg = _params[i];
                                ch->setMode(CH_MODE_K, mark);
                            }
                            else
                            {
                                _response += ":irc.server.com 467 ";
                                _response += me->getNickname();
                                _response += " ";
                                _response += ch->getName();
                                _response += " :Channel key already set";
                                _response += CRFL;
                            }
                        }
                    }
                    else if (mode_for_key[0] == "+o")
                    {
                        User *op = findUser(_params[i]);
                        if (op == NULL)
                        {
                            _response += ":irc.server.com 401 ";
                            _response += me->getNickname();
                            _response += " ";
                            _response += _params[i];
                            _response += " :No such nick";
                            _response += CRFL;
                        }
                        else
                        {
                            // 관리자로 추가할 건데 관리자로 이미 있으면 pass
                            // 따라서 마지막에 send 하는 것도 무시
                            if (ch->isMember(op))
                            {
                                ch->addOperator(op);
                                ch->removeMember(op);

                                mode_msg += "+o";
                                if (last_mode_msg != "")
                                {
                                    middle_mode_msg += last_mode_msg;
                                    middle_mode_msg += " ";
                                }
                                last_mode_msg = _params[i];
                            }
                        }
                    }
                    else if (mode_for_key[0] == "-o")
                    {
                        User *mem = findUser(_params[i]);
                        if (mem == NULL)
                        {
                            _response += ":irc.server.com 401 ";
                            _response += me->getNickname();
                            _response += " ";
                            _response += _params[i];
                            _response += " :No such nick";
                            _response += CRFL;
                        }
                        else
                        {
                            if (ch->isOperator(mem))
                            {
                                ch->addMember(mem);
                                ch->removeOperator(mem);

                                mode_msg += "-o";
                                if (last_mode_msg != "")
                                {
                                    middle_mode_msg += last_mode_msg;
                                    middle_mode_msg += " ";
                                }
                                last_mode_msg = _params[i];
                            }
                        }
                    }
                    else if (mode_for_key[0] == "+l")
                    {
                        int limit = strtol(_params[i].c_str(), NULL, 10);
                        //음수와 오버플로우 감지
                        if (_params[i].size() > 10 || (_params[i].size() == 10 && _params[i] > "2147483647") || limit < 0)
                        {
                            _response += ":irc.server.com 696 ";
                            _response += me->getNickname();
                            _response += " ";
                            _response += ch->getName();
                            _response += " ";
                            _response += mode_for_key[1];
                            _response += " ";
                            _response += _params[i];
                            _response += " :Invalid limit mode parameter. Syntax: <limit>.";
                            _response += CRFL;
                        }
                        else
                        {
                            ch->setUserlimit(limit);

                            mode_msg += "+l";
                            if (last_mode_msg != "")
                            {
                                middle_mode_msg += last_mode_msg;
                                middle_mode_msg += " ";
                            }
                            std::stringstream ss;
                            ss << limit;
                            last_mode_msg = ss.str();
                            ch->setMode(CH_MODE_L, mark);
                        }
                    }
                    mode_key_count--;
                    if (mode_key_count == 0)
                    {
                        is_mode = true;
                        mode_for_key.clear();
                    }
                    else
                        mode_for_key.erase(mode_for_key.begin());
                }
            }
            if (!is_mode)
            {
                // ERR_INVALIDMODEPARAM (696)
                _response += ":irc.server.com 696 ";
                _response += me->getNickname();
                _response += " ";
                _response += ch->getName();
                _response += " ";
                _response += mode_for_key[0][1];
                if (mode_for_key[0][1] == 'k')
                    _response += " * :You must specify a parameter for the key mode. Syntax: <key>.";
                else if (mode_for_key[0][1] == 'l')
                    _response += " * :You must specify a parameter for the limit mode. Syntax: <limit>.";
                else if (mode_for_key[0][1] == 'o')
                    _response += " * :You must specify a parameter for the op mode. Syntax: <nick>.";
                _response += CRFL;
                return ;
            }
            // 하나라도 모드가 성공적으로 변경된 경우, 마지막에 모든 사용자들에게 채널 권한이 변경되었다고 알림
            // 바뀐 모드에 대해 sendtoall에 추가하고 sendtoall 함수 실행
            if (mode_msg != " ")
            {
                for (int i = 0; i < 5; i++)
                {
                    std::string sendtoall = ":";
                    sendtoall += me->getNickUserHost();
                    sendtoall += " MODE ";
                    sendtoall += ch->getName();
                    sendtoall += " ";
                    if (last_mode_msg == "")
                    {
                        sendtoall += ":";
                        sendtoall += mode_msg;
                    }
                    else
                    {
                        sendtoall += mode_msg;
                        if (middle_mode_msg == "")
                            sendtoall += " :";
                        else
                        {
                            sendtoall += " ";
                            sendtoall += middle_mode_msg;
                            sendtoall += ":";
                        }
                        sendtoall += last_mode_msg;
                    }
                    sendtoall += CRFL;
                    ch->sendToAll(sendtoall);
                    break;
                }
            }
        }
    }
    else    // 사용자 mode 변경
    {
        User *user = findUser(_params[0]);
        if (user == NULL)
        {
            _response += ":irc.server.com 401 ";
            _response += me->getNickname();
            _response += " ";
            _response += _params[0];
            _response += " :No such nick";
            _response += CRFL;
            return ;
        }

        if (user->getClientSocket() != _clientSocket)
        {
            _response += ":irc.server.com 502 ";
            _response += me->getNickname();
            _response += " :Cant change mode for other users";
            _response += CRFL;
            return ;
        }

        if (p_size == 1)
        {
            // RESPONSE 221
            // 사용자 모드 조회
            _response += ":irc.server.com 221 ";
            _response += me->getNickname();
            _response += " :+";
            if (me->getMode())
                _response += "i";
            _response += CRFL;
        }
        else
        {
            // parse modestring and mode(부호 확정하고, i 이외에 다른 문자 거르기)
            // 다른 문자가 나오면 ERR_UMODEUNKNOWNFLAG (501)
            // 선형탐색이 아니라 다른 문자에 대한 처리를 해주고, 가장 마지막에 있는 모드 인자만 처리해준다.
            for (size_t i = 0; i < _params[1].size(); i++)
            {
                if (_params[1][i] != 'i' && _params[1][i] != '-' && _params[1][i] != '+')
                {
                    _response += ":irc.server.com 501 ";
                    _response += me->getNickname();
                    _response += " ";
                    _response += _params[1][i];
                    _response += " :is not a recognised user mode.";
                    _response += CRFL;
                }
            }
            size_t i = _params[1].find('i');
            if (i != std::string::npos)
            {
                size_t is_minus = (_params[1].substr(0, i)).rfind('-');
                if (is_minus != std::string::npos)
                {
                    // is_plus 찾아서 비교
                    size_t is_plus = (_params[1].substr(0, i)).rfind('+');
                    if (is_plus != std::string::npos)
                    {
                        if (is_minus > is_plus)
                        {
                            // minus 처리
                            if (me->getMode() != false)
                            {
                                me->setMode(false);
                                _response += ":";
                                _response += me->getNickUserHost();
                                _response += " MODE ";
                                _response += me->getNickname();
                                _response += " :-i";
                                _response += CRFL;
                                me->setMode(false);
                            }
                        }
                        else
                        {
                            // plus 처리
                            if (me->getMode() != true)
                            {
                                _response += ":";
                                _response += me->getNickUserHost();
                                _response += " MODE ";
                                _response += me->getNickname();
                                _response += " :+i";
                                _response += CRFL;
                                me->setMode(true);
                            }
                        }
                    }
                    else
                    {
                        // 자동으로 minus 처리
                        if (me->getMode() != false)
                        {
                            me->setMode(false);
                            _response += ":";
                            _response += me->getNickUserHost();
                            _response += " MODE ";
                            _response += me->getNickname();
                            _response += " :-i";
                            _response += CRFL;
                            me->setMode(false);
                        }
                    }
                }
                else
                {
                    // 자동으로 plus 처리
                    if (me->getMode() != true)
                    {
                        _response += ":";
                        _response += me->getNickUserHost();
                        _response += " MODE ";
                        _response += me->getNickname();
                        _response += " :+i";
                        _response += CRFL;
                        me->setMode(true);
                    }
                }
            }
        }
    }
}

// :irc.server.com 353 root_ = #test :@root root_
// :irc.server.com 366 root_ #test :End of /NAMES list.
// 매개변수가 없을 경우 모든 채널과 그 채널들의 멤버를 보여준다고 나와있지만 실제 테스트 했을땐 아무것도 안나옴.
std::string Command::names(std::string chname)
{
    std::vector<std::string> names;
    std::string response;
    User *user = findUser(_clientSocket);
    Channel *channel = findChannel(chname);
    response = ":irc.server.com 353 " + user->getNickname() + " = " + channel->getName() + " :";
    for (size_t i = 0; i < channel ->getOperators().size(); i++)
    {
        names.push_back("@" + channel->getOperators()[i]->getNickname());
    }
    for (size_t i = 0; i < channel ->getMembers().size(); i++)
    {
        names.push_back(channel->getMembers()[i]->getNickname());
    }
    for (size_t i = 0; i < names.size(); i++)
    {
        response += names[i];
        if (i != names.size() - 1)
            response += " ";
    }
    response += CRFL;
    response += ":irc.server.com 366 " + user->getNickname() + " " + channel->getName() + " :End of /NAMES list." + CRFL;
    return response;
}

// ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
// ERR_BADCHANMASK                 ERR_CHANOPRIVSNEEDED
// ERR_NOTONCHANNEL
void Command::kick()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    std::string response;
    std::string comment;

    User *user = findUser(_clientSocket);
    if (_params.size() < 2)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += user->getNickname();
        _response += " KICK :Not enough parameters";
        _response += CRFL;
        return ;
    }

    Channel *channel = findChannel(_params[0]);
    if (channel == NULL)
    {
        // ERR_NOSUCHCHANNEL
        _response += ":irc.server.com 403 ";
        _response += user->getNickname();
        _response += " ";
        _response += _params[0];
        _response += " :No such channel";
        _response += CRFL;
        return ;
    }

    User *kickee = findUser(_params[1]);
    if (kickee == NULL)
    {
        // ERR_NOSUCHNICK
        _response += ":irc.server.com 401 ";
        _response += user->getNickname();
        _response += " ";
        _response += _params[1];
        _response += " :No such nick/channel";
        _response += CRFL;
        return ;
    }

    if (!channel->isMember(user) && !channel->isOperator(user))
    {
        // ERR_NOTONCHANNEL
        _response += ":irc.server.com 442 ";
        _response += user->getNickname();
        _response += " ";
        _response += channel->getName();
        _response += " :You're not on that channel";
        _response += CRFL;
        return ;
    }
    if (!channel->isOperator(user))
    {
        // ERR_CHANOPRIVSNEEDED
        _response += ":irc.server.com 482 ";
        _response += user->getNickname();
        _response += " ";
        _response += channel->getName();
        _response += " :You're not channel operator";
        _response += CRFL;
        return ;
    }
    if (_params.size() > 2)
    {
        _params.erase(_params.begin(), _params.begin() + 2);
        comment = paramsJoin();
    }
    response = ":" + user->getNickUserHost() + " KICK " + channel->getName() + " " + kickee->getNickname() + " :" + comment + CRFL;
    channel->sendToAll(response);
    kickee->partChannel(channel);
    if (channel->getUsercount() == 0)
        eraseChannel(channel);
}

// ERR_NEEDMOREPARAMS              ERR_NOSUCHNICK
// ERR_NOTONCHANNEL                ERR_USERONCHANNEL
// ERR_CHANOPRIVSNEEDED
void Command::invite()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    std::string response;
    User *user = findUser(_clientSocket);
    if (_params.size() < 2)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += user->getNickname();
        _response += " INVITE :Not enough parameters";
        _response += CRFL;
        return ;
    }
    User *invitee = findUser(_params[0]);
    if (invitee == NULL)
    {
        // ERR_NOSUCHNICK
        _response += ":irc.server.com 401 ";
        _response += user->getNickname();
        _response += " ";
        _response += _params[0];
        _response += " :No such nick/channel";
        _response += CRFL;
        return ;
    }
    Channel *channel = findChannel(_params[1]);
    if (channel == NULL)
    {
        // ERR_NOSUCHCHANNEL
        _response += ":irc.server.com 403 ";
        _response += user->getNickname();
        _response += " ";
        _response += _params[1];
        _response += " :No such channel";
        _response += CRFL;
        return ;
    }
    if (!channel->isMember(user) && !channel->isOperator(user))
    {
        // ERR_NOTONCHANNEL
        _response += ":irc.server.com 442 ";
        _response += user->getNickname();
        _response += " ";
        _response += channel->getName();
        _response += " :You're not on that channel";
        _response += CRFL;
        return ;
    }
    if (!channel->isOperator(user))
    {
        // ERR_CHANOPRIVSNEEDED
        _response += ":irc.server.com 482 ";
        _response += user->getNickname();
        _response += " ";
        _response += channel->getName();
        _response += " :You're not channel operator";
        _response += CRFL;
        return ;
    }
    if (channel->isMember(invitee) || channel->isOperator(invitee))
    {
        // ERR_USERONCHANNEL
        _response += ":irc.server.com 443 ";
        _response += user->getNickname();
        _response += " ";
        _response += invitee->getNickname();
        _response += " ";
        _response += channel->getName();
        _response += " :is already on channel";
        _response += CRFL;
        return ;
    }
    response = ":" + user->getNickUserHost() + " INVITE " + invitee->getNickname() + " :" + channel->getName() + CRFL;
    invitee->addInvitation(channel);
    send(invitee->getClientSocket(), response.c_str(), response.length(), 0);
}

// ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
// ERR_CHANOPRIVSNEEDED

void Command::topic()
{
    if (findUser(_clientSocket) == NULL || findUser(_clientSocket)->getWelcome() == false)
        return ;
    std::string response;
    std::string param;
    std::string channelname;
    User *user = findUser(_clientSocket);
    if (_params.size() == 0)
    {
        // ERR_NEEDMOREPARAMS
        _response += ":irc.server.com 461 ";
        _response += user->getNickname();
        _response += " TOPIC :Not enough parameters";
        _response += CRFL;
        return;
    }
    Channel *ch = user->getMyChannel(_params[0]);
    channelname = _params[0];
    _params.erase(_params.begin());
    if (ch == NULL)
    {
        // ERR_NOTONCHANNEL
        _response += ":irc.server.com 442 ";
        _response += user->getNickname();
        _response += " ";
        _response += channelname;
        _response += " :You're not on that channel";
        _response += CRFL;
        return ;
    }
    if (_params.size() == 0)
    {
        if (ch->getTopic() == "")
        {
            // RPL_NOTOPIC
            _response += ":irc.server.com 331 ";
            _response += user->getNickname();
            _response += " ";
            _response += ch->getName();
            _response += " :No topic is set";
            _response += CRFL;
            return ;
        }
        // RPL_TOPIC
        _response += ":irc.server.com 332 ";
        _response += user->getNickname();
        _response += " ";
        _response += ch->getName();
        _response += " :";
        _response += ch->getTopic();
        _response += CRFL;
        return ;
    }
    param = paramsJoin();
    if (!(ch->getMode(CH_MODE_T)) || (ch->getMode(CH_MODE_T) && ch->isOperator(user)))
    {
        ch->setTopic(param);
        response += ":" + user->getNickUserHost() + " TOPIC " + ch->getName() + " :" + param + CRFL;
        ch->sendToAll(response);
    }
    else
    {
        // ERR_CHANOPRIVSNEEDED
        _response += ":irc.server.com 482 ";
        _response += user->getNickname();
        _response += " ";
        _response += ch->getName();
        _response += " :You're not channel operator";
        _response += CRFL;
    }
}
// 127.000.000.001.42728-127.000.000.001.06667: QUIT :leaving
// 127.000.000.001.06667-127.000.000.001.42728: ERROR :Closing link: (root@127.0.0.1) [Quit: leaving]
// 127.000.000.001.06667-127.000.000.001.42726: :nickname2!root@127.0.0.1 QUIT :Quit: leaving
int Command::quit()
{
    std::string response;
    std::string response_me;
    User *user = findUser(_clientSocket);
    if (!user)
        return 0;
    if (_params.size() == 0)
    {
        response = ":" + user->getNickUserHost() + " QUIT :" + "leaving" + CRFL;
        response_me = "ERROR :Closing link: (" + user->getNickUserHost() + ") [Quit: leaving]" + CRFL;
    }
    else
    {
        response = ":" + user->getNickUserHost() + " QUIT :" + paramsJoin() + CRFL;
        response_me = "ERROR :Closing link: (" + user->getNickUserHost() + ") [Quit: " + paramsJoin() + "]" + CRFL;
    }
    std::vector<Channel*> chs = user->getMyChannels();
    send(_clientSocket, response_me.c_str(), response_me.length(), 0);
    for (size_t i = 0; i < chs.size(); i++)
    {
        Channel *ch = chs[i];
        ch->sendtoAllButOne(response, user);
        user->partChannel(ch);
        if (ch->getUsercount() == 0)
            eraseChannel(ch);
    }
    eraseUser(_clientSocket);
    return 1;
}

User *Command::findUser(std::string nickname)
{
    for (size_t i = 0; i < _users.size(); i++)
    {
        if (_users[i]->getNickname() == nickname)
            return _users[i];
    }
    return NULL;
}

User *Command::findUser(int clientSocket)
{
    for (size_t i = 0; i < _users.size(); i++)
    {
        if (_users[i]->getClientSocket() == clientSocket)
            return _users[i];
    }
    return NULL;
}

Channel *Command::findChannel(std::string name)
{
    for (size_t i = 0; i < _channels.size(); i++)
    {
        if (_channels[i]->getName() == name)
            return _channels[i];
    }
    return NULL;
}

void Command::eraseChannel(Channel *channel)
{
    if (channel == NULL)
        return ;
    for (size_t i = 0; i < _channels.size(); i++)
    {
        if (_channels[i] == channel)
        {
            _channels.erase(_channels.begin() + i);
            delete channel;
            break;
        }
    }
}

void Command::eraseUser(int clientSocket)
{
    for (size_t i = 0; i < _users.size(); i++)
    {
        if (_users[i]->getClientSocket() == clientSocket)
        {
            User *user = _users[i];
            _users.erase(_users.begin() + i);
            delete user;
            return ;
        }
    }
}

std::string Command::paramsJoin()
{
    std::string res;
    for (size_t i = 0; i < _params.size(); i++)
    {
        res += _params[i];
        if (i != _params.size() - 1)
            res += " ";
    }
    return res;
}

// PASS
// NICK
// USER
// QUIT
// JOIN
// PRIVMSG

// KICK
// INVITE
// TOPIC
// MODE

// PING
// PONG
