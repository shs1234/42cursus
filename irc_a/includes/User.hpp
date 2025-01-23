#pragma once

#include <iostream>
#include <vector>

// i - marks a users as invisible;

class User
{
private:
    int _clientSocket;
    std::string _nickname;
    std::string _username;
    std::string _hostname;
    std::string _servername;
    std::string _realname;

    bool _pass;
    bool _nick;
    bool _user;
    bool _welcome;

    std::vector<class Channel*> _myChannels;
    std::vector<Channel*> _invited;

    bool _mode;

public:
    User();
    ~User();

    void addChannel(Channel* channel);
    void removeChannel(Channel* channel);

    void partChannel(Channel* channel);

    void addInvitation(Channel* channel);
    void removeInvitation(Channel* channel);

    void setClientSocket(int clientSocket) { _clientSocket = clientSocket; }
    void setNickname(std::string nickname) { _nickname = nickname; }
    void setUsername(std::string username) { _username = username; }
    void setHostname(std::string hostname) { _hostname = hostname; }
    void setServername(std::string servername) { _servername = servername; }
    void setRealname(std::string realname) { _realname = realname; }
    void setMode(bool value) { _mode = value; }
    void setPass(bool value) { _pass = value; }
    void setNick(bool value) { _nick = value; }
    void setUser(bool value) { _user = value; }
    void setWelcome(bool value) { _welcome = value; }

    int getClientSocket() { return _clientSocket; }
    std::string getNickname() { return _nickname; }
    std::string getUsername() { return _username; }
    std::string getHostname() { return _hostname; }
    std::string getServername() { return _servername; }
    std::string getRealname() { return _realname; }
    std::vector<Channel*> getMyChannels() { return _myChannels; }
    bool getPass() { return _pass; }
    bool getNick() { return _nick; }
    bool getUser() { return _user; }
    bool getWelcome() { return _welcome; }

    Channel* getMyChannel(std::string name);
    Channel* getInvitation(std::string name);
    bool getMode() { return _mode; }

    std::string getNickUserHost() { return _nickname + "!" + _username + "@" + _hostname; }
};
