#include "Server.hpp"


void Server::join(int i, std::string channelName, std::string channelPass)
{
    int ch = whichChannel(channelName);
    if (ch == -1)
    {
        channelArray.push_back(Channel(channelName, channelPass));
        channelArray[channelArray.size() - 1].addChannelClients(clientArray[i]);
        channelArray[channelArray.size() - 1].addOperator(i);
        std::string identity = ":" + clientArray[i].getNickname() + "!" + clientArray[i].getUsername() + "@" + getHostname();
        sendFunct(clientArray[i].getSocketFd(), JOIN(identity,channelName));
        return;
    }
    for(int k = 0; k < (int)channelArray[ch].getChannelClients().size(); k++)
    {
        if (!channelArray[ch].getChannelClients()[k].getNickname().compare(clientArray[i].getNickname())) 
        {
            sendFunct(clientArray[i].getSocketFd(), "You already in this channel\r\n");
            return;
        }
    }
    if((channelArray[ch].getPassword().compare(channelPass)) == 0)
    {
        channelArray[ch].addChannelClients(clientArray[i]);
        std::string identity = ":" + clientArray[i].getNickname() + "!" + clientArray[i].getUsername() + "@" + getHostname();
        sendFunct(clientArray[i].getSocketFd(), JOIN(identity, channelName));
        return;
    }
    sendFunct(clientArray[i].getSocketFd(), BADCHANNEL(channelName));
}


void    Server::part( int i, std::string token )
{
    if (token[0] != '#')
    {
        sendFunct(clientArray[i].getSocketFd(), "The channel name should start with '#' !! \r\n");
        return;
    }

    if (whichChannel(token) == -1)
    {
        sendFunct(clientArray[i].getSocketFd(), "Any channel not found with name " + token + "\r\n");
    }
    for (int ch = 0; ch < (int)channelArray.size(); ch++)
    {
        for (int c = 0; c < (int)channelArray[ch].getChannelClients().size(); c++)
        {
            if (channelArray[ch].getChannelClients()[c].getNickname().compare(clientArray[i].getNickname()) == 0)
            {
                channelArray[ch].eraseChannelClients(c);
                if ((int)channelArray[ch].getChannelClients().size() == 0)
                {
                    channelArray.erase(channelArray.begin() + ch);
                    continue;
                }
                for (int o = 0; o < (int)channelArray[ch].getOperator().size(); o++)
                {
                    if (i == channelArray[ch].getOperator()[o])
                    {
                        channelArray[ch].eraseOperator(o);
                        if (channelArray[ch].getOperator().size() == 0)
                        {
                            if ((int)channelArray[ch].getChannelClients().size() >= c)
                            {
                                std::string identity = ":" + channelArray[ch].getChannelClients()[c].getNickname() + "!" + channelArray[ch].getChannelClients()[c].getUsername() + "@" + getHostname();
                                channelArray[ch].addOperator(findIndex(channelArray[ch].getChannelClients()[c].getNickname()));
                                sendFunct(channelArray[ch].getChannelClients()[c].getSocketFd(),identity + " You are operator now!\r\n");
                            }
                            else
                            {
                                channelArray[ch].addOperator(findIndex(channelArray[ch].getChannelClients()[0].getNickname()));
                                std::string identity = ":" + channelArray[ch].getChannelClients()[0].getNickname() + "!" + channelArray[ch].getChannelClients()[0].getUsername() + "@" + getHostname();
                                sendFunct(channelArray[ch].getChannelClients()[0].getSocketFd(), identity + " You are operator now!\r\n");

                            }
                        }

                    }
                }
            }
        }
    }
}

void Server::quit(int i)
{
    sendFunct(clientArray[i].getSocketFd(), IDENTITY(clientArray[i].getNickname(), clientArray[i].getUsername(), getHostname()) + "  QUIT :Quit BYE!\r\n");
    for (int ch = 0; ch < (int)channelArray.size(); ch++)
    {
        for (int c = 0; c < (int)channelArray[ch].getChannelClients().size(); c++)
        {
            if (channelArray[ch].getChannelClients()[c].getNickname().compare(clientArray[i].getNickname()) == 0)
            {
                channelArray[ch].eraseChannelClients(c);
                if ((int)channelArray[ch].getChannelClients().size() == 0)
                {
                    channelArray.erase(channelArray.begin() + ch);
                    continue;
                }
                for (int o = 0; o < (int)channelArray[ch].getOperator().size(); o++)
                {
                    if (i == channelArray[ch].getOperator()[o])
                    {
                        channelArray[ch].eraseOperator(o);
                        if (channelArray[ch].getOperator().size() == 0)
                        {
                            if ((int)channelArray[ch].getChannelClients().size() >= c)
                            {
                                std::string identity = ":" + channelArray[ch].getChannelClients()[c].getNickname() + "!" + channelArray[ch].getChannelClients()[c].getUsername() + "@" + getHostname();
                                channelArray[ch].addOperator(findIndex(channelArray[ch].getChannelClients()[c].getNickname()));
                                sendFunct(channelArray[ch].getChannelClients()[c].getSocketFd(),identity + " You are operator now!\r\n");
                            }
                            else
                            {
                                channelArray[ch].addOperator(findIndex(channelArray[ch].getChannelClients()[0].getNickname()));
                                std::string identity = ":" + channelArray[ch].getChannelClients()[0].getNickname() + "!" + channelArray[ch].getChannelClients()[0].getUsername() + "@" + getHostname();
                                sendFunct(channelArray[ch].getChannelClients()[0].getSocketFd(), identity + " You are operator now!\r\n");

                            }
                        }

                    }
                }
            }
        }
    }
    close (clientArray[i].getSocketFd());
    clientArray.erase(clientArray.begin() + i);
}

int Server::whichChannel(std::string channelName)
{
    int index = (int)channelArray.size() - 1;
    
    while (index >= 0)
    {
        if (!channelArray[index].getName().compare(channelName))
            return (index);
        index--;
    }
    return (-1);
}

int Server::findIndex(std::string nick)
{
    for(int i = 0; i< (int)clientArray.size(); i++)
    {
        if (clientArray[i].getNickname().compare(nick)== 0)
            return (i);
    }
    return (-1);
}

