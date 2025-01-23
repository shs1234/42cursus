#include "User.hpp"
#include "Channel.hpp"

User::User() :
_clientSocket(0),
_nickname(""),
_username(""),
_hostname(""),
_servername(""),
_realname(""),
_pass(false),
_nick(false),
_user(false),
_welcome(false),
_mode(false) {}

User::~User()
{
    for (size_t i = 0; i < _myChannels.size(); i++)
        _myChannels[i] = NULL;
    for (size_t i = 0; i < _invited.size(); i++)
        _invited[i] = NULL;
}

void User::addChannel(Channel* channel)
{
    _myChannels.push_back(channel);
}

void User::removeChannel(Channel* channel)
{
    if (channel == NULL)
        return ;
    for (size_t i = 0; i < _myChannels.size(); i++)
    {
        if (_myChannels[i] == channel)
        {
            _myChannels.erase(_myChannels.begin() + i);
            break;
        }
    }
}

void User::partChannel(Channel* channel)
{
    if (channel == NULL)
        return ;
    channel->removeMember(this);
    channel->removeOperator(this);
    for (size_t i = 0; i < _myChannels.size(); i++)
    {
        if (_myChannels[i] == channel)
        {
            _myChannels.erase(_myChannels.begin() + i);
            break;
        }
    }
}

void User::addInvitation(Channel* channel)
{
    if (channel == NULL)
        return ;
    _invited.push_back(channel);
}

void User::removeInvitation(Channel* channel)
{
    if (channel == NULL)
        return ;
    for (size_t i = 0; i < _myChannels.size(); i++)
    {
        if (_invited[i] == channel)
        {
            _invited.erase(_invited.begin() + i);
            break;
        }
    }
}

Channel* User::getMyChannel(std::string name)
{
    for (size_t i = 0; i < _myChannels.size(); i++)
    {
        if (_myChannels[i]->getName() == name)
            return _myChannels[i];
    }
    return NULL;
}

Channel* User::getInvitation(std::string name)
{
    for (size_t i = 0; i < _invited.size(); i++)
    {
        if (_invited[i]->getName() == name)
            return _invited[i];
    }
    return NULL;
}
