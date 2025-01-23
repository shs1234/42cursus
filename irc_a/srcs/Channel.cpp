#include "Channel.hpp"
#include "User.hpp"

Channel::Channel() : _name(""), _topic(""), _userCount(0), _pw(""), _userLimit(0)
{
    for (int i = 0; i < CH_MODES; i++)
        _modes[i] = false;
}
Channel::~Channel()
{
    for (size_t i = 0; i < _members.size(); i++)
        _members[i] = NULL;
    for (size_t i = 0; i < _operators.size(); i++)
        _operators[i] = NULL;
}

void Channel::sendToAll(std::string message)
{
    for (size_t i = 0; i < _operators.size(); i++)
    {
        send(_operators[i]->getClientSocket(), message.c_str(), message.length(), 0);
    }
    for (size_t i = 0; i < _members.size(); i++)
    {
        send(_members[i]->getClientSocket(), message.c_str(), message.length(), 0);
    }
}

void Channel::sendtoAllButOne(std::string message, User* user)
{
    for (size_t i = 0; i < _operators.size(); i++)
    {
        if (_operators[i] != user)
            send(_operators[i]->getClientSocket(), message.c_str(), message.length(), 0);
    }
    for (size_t i = 0; i < _members.size(); i++)
    {
        if (_members[i] != user)
            send(_members[i]->getClientSocket(), message.c_str(), message.length(), 0);
    }
}


void Channel::addMember(User* user)
{
    _members.push_back(user);
    _userCount++;
}

void Channel::removeMember(User* user)
{
    for (size_t i = 0; i < _members.size(); i++)
    {
        if (_members[i] == user)
        {
            _members.erase(_members.begin() + i);
            _userCount--;
            break;
        }
    }
}

void Channel::addOperator(User* user)
{
    _operators.push_back(user);
    _userCount++;
}

void Channel::removeOperator(User* user)
{
    for (size_t i = 0; i < _operators.size(); i++)
    {
        if (_operators[i] == user)
        {
            _operators.erase(_operators.begin() + i);
            _userCount--;
            break;
        }
    }
}

bool Channel::isOperator(User* user)
{
    for (size_t i = 0; i < _operators.size(); i++)
    {
        if (_operators[i] == user)
            return true;
    }
    return false;
}

bool Channel::isMember(User* user)
{
    for (size_t i = 0; i < _members.size(); i++)
    {
        if (_members[i] == user)
            return true;
    }
    return false;
}
