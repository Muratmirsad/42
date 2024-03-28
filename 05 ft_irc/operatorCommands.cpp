#include "Server.hpp"
#include "Messages.hpp"

void    Server::kick(int i, std::string channelName, std::string clientNick) {
// kicklenen biri operatörse
    for (int j = 0; j < (int)channelArray.size(); j++) 
    {
        if (channelName.compare(channelArray[j].getName()) == 0)
        {
            for (int c = 0; c < (int)channelArray[j].getChannelClients().size(); c++) 
            {
                if ((clientNick.compare(channelArray[j].getChannelClients()[c].getNickname()) == 0) 
                    && (channelArray[j].areYouOperator(i) != -1)
                    && (clientArray[i].getNickname().compare(channelArray[j].getChannelClients()[c].getNickname()) == 0))
                {
                    std::string kickerMessage = IDENTITY(clientArray[i].getNickname(),clientArray[i].getUsername(), getHostname()) + ": 441 " + clientArray[i].getNickname() + " : you kicked " + clientNick + "\r\n";
                    std::string kickedMessage = ": 441 " + clientNick + " : you are kicked from " + channelArray[j].getName() + "\r\n";
                    sendFunct(clientArray[i].getSocketFd(), kickerMessage);
                    sendFunct(channelArray[j].getChannelClients()[c].getSocketFd(), kickedMessage);
                    channelArray[j].eraseChannelClients(c);
                    return;
                }
            }
        }
    }
    sendFunct(clientArray[i].getSocketFd(), "No such channel/user or you are not operator!\r\n");

}


void Server::topic(int i, std::string channelName, std::string topicMessage) {
    int flag = 0;
     for (int j = 0; j < (int)channelArray.size(); j++) 
    {
        if (channelName == channelArray[j].getName()) 
        {
            flag = 1;
            if (channelArray[j].areYouOperator(i) != -1)
            {
                channelArray[j].setTopic(topicMessage);
                for (int k = 0; k < (int)channelArray[j].getChannelClients().size(); k++) {
                    std::string msg =  ": 332 " + channelArray[j].getChannelClients()[k].getNickname() + " " + channelArray[j].getName() + ":" + channelArray[j].getTopic() + "\r\n";
                    sendFunct(channelArray[j].getChannelClients()[k].getSocketFd(), msg);
                }
                return;
            }
            else
                sendFunct(clientArray[i].getSocketFd(), ": 403 : " +  clientArray[i].getNickname() + "you are not operator!\r\n");
            break;
        }
    }
    if (flag == 0)
        sendFunct(clientArray[i].getSocketFd(),": 403 : " + clientArray[i].getNickname() + " " + channelName+ " :There is no channel\r\n");
}
