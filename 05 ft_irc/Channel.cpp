#include "Channel.hpp"

std::string Channel::getName(void)
{
    return(this->_name);
}

std::string Channel::getPassword(void)
{
    return(this->_password);
}

void Channel::setName(std::string name)
{
    this->_name = name;
}

void Channel::setPassword(std::string password)
{
    this->_password = password;
}

Channel::Channel(std::string name, std::string password)
{
    this->_name = name;
    this->_password = password;
}
Channel::Channel(std::string name, std::string password, Client &client)
{
    this->_name = name;
    this->_password = password;
    channelClients.push_back(client);
}

void Channel::setTopic(std::string topic) 
{
    this->_topic = topic;
}

std::string Channel::getTopic() {
    return (_topic);
}

void Channel::addOperator(int index) 
{
    _operator.push_back(int());
    _operator[_operator.size() - 1] = index;
}

std::vector<int> Channel::getOperator() 
{
    return (this->_operator);
}

Channel::Channel()
{
    
}

Channel::~Channel()
{

}


void    Channel::eraseOperator(int op) {
    _operator.erase(_operator.begin() + op);
}


int Channel::areYouOperator(int cl)
{
   for (int i = 0; i < (int)_operator.size(); i++)
   {
        if (cl == _operator[i])
            return(i);
   }
   return (-1);
}

std::vector<Client> Channel::getChannelClients()
{
    return(channelClients);
}


void Channel::addChannelClients(Client &ref) {
    channelClients.push_back(Client());
    channelClients[(int)channelClients.size() - 1].setSocketFd(ref.getSocketFd());
    channelClients[(int)channelClients.size() - 1].setNickname(ref.getNickname());
}

void  Channel::eraseChannelClients(int c)
{
   channelClients.erase(channelClients.begin() + c);

}
