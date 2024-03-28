#include "Server.hpp"

void        Server::setHostname(std::string _host)
{
    this->hostname = _host;
}

std::string Server::getHostname()
{
    return (hostname);
}

int Server::isNicknameInUse(std::string _nick) {
    for (int i = 0; i < (int)clientArray.size(); i++) 
    {
        if (!clientArray[i].getNickname().compare(_nick))
            return (1);
    }
    return (0);
}


void Server::sendFunct(int fd, std::string raw) 
{
    const char *mess = raw.c_str();
    send(fd, mess, strlen(mess), 0);
}

int Server::areYouIn(int cl, int ch) {
    for (int i = 0; i < (int)channelArray[ch].getChannelClients().size(); i++)
    {
        if (!channelArray[ch].getChannelClients()[i].getNickname().compare(clientArray[cl].getNickname()))
            return (1);
    }
    return (0);
}