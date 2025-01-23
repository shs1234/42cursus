#pragma once

#include <iostream>
#include <vector>
#include <sys/socket.h>
#include "User.hpp"
#include "Channel.hpp"
#include <sstream>
#include <unistd.h>
#include <cstdlib>

#define CRFL "\r\n"

class Command
{
private:
    int _clientSocket;
    std::string _msg;
    std::vector<User*> &_users;
    std::vector<Channel*> &_channels;
    int _password;

    std::string _prefix;
    std::string _command;
    std::vector<std::string> _params;

    struct Commands
    {
        std::string _prefix;
        std::string _command;
        std::vector<std::string> _params;
    };
    std::vector<Commands> _commands;

    std::string _response;

    void parseMessage();

    void welcomeMsg();

    User* findUser(std::string nickname);
    User* findUser(int clientSocket);
    void eraseUser(int clientSocket);

    Channel* findChannel(std::string name);
    void eraseChannel(Channel* channel);

    std::string paramsJoin();


    int pass();
    int nick();
    int user();
    void join();
    void privmsg();
    void part();
    void mode();
    void topic();
    std::string names(std::string chname);
    void invite();
    void kick();
    void ping();

public:
    Command(int clientSocket, std::string msg, std::vector<User*> &us, std::vector<Channel*> &ch, int password);
    ~Command();

    void printparsing();

    int exec();
    int quit();
};
