#pragma once

#include <iostream>
#include <vector>
#include <sys/socket.h>

#define CRFL "\r\n"
#define CH_MODES 4
// o - give/take channel operator privileges;
// p - private channel flag;
// s - secret channel flag;
// i - invite-only channel flag;
// t - topic settable by channel operator only flag;
// n - no messages to channel from clients on the outside;
// m - moderated channel;
// l - set the user limit to channel;
// b - set a ban mask to keep users out;
// v - give/take the ability to speak on a moderated channel;
// k - set a channel key (password).
#define CH_MODE_I 0
#define CH_MODE_T 1
#define CH_MODE_K 2
#define CH_MODE_L 3

class Channel
{
private:
    bool _modes[CH_MODES];
    std::string _name;
    std::string _topic;
    std::vector<class User*> _operators;
    std::vector<User*> _members;
    int _userCount;

    std::string _pw;    // mode k
    int _userLimit;     // mode l
    
public:
    Channel();
    ~Channel();

    void sendToAll(std::string message);
    void sendtoAllButOne(std::string message, User* user);

    void addMember(User* user);
    void removeMember(User* user);

    void addOperator(User* user);
    void removeOperator(User* user);

    void setName(std::string name) { _name = name; }
    void setMode(int mode, bool value) { _modes[mode] = value; }
    void setTopic(std::string topic) { _topic = topic; }
    void setPw(std::string pw) { _pw = pw; }
    void setUserlimit(int userLimit) { _userLimit = userLimit; }

    std::string getName() { return _name; }
    bool getMode(int mode) { return _modes[mode]; }
    std::string getTopic() { return _topic; }
    int getUsercount() { return _userCount; }
    std::string getPw() { return _pw; }
    int getUserlimit() { return _userLimit; }
    std::vector<User*> getMembers() { return _members; }
    std::vector<User*> getOperators() { return _operators; }
    
    bool isOperator(User* user);
    bool isMember(User* user);
};
