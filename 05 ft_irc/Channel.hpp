#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"
#include <string>

class Client;

class Channel{
    private:
        std::string             _name;
        std::string             _password;
        std::string             _topic;
        std::vector<int>        _operator;
        std::vector<Client>		channelClients;

    public:
        Channel(std::string name, std::string password, Client &client);
        Channel(std::string name, std::string password);

        Channel();
        ~Channel();
        std::string         getName(void);
        std::string         getPassword(void);
        void                setName(std::string name);
        void			    setPassword(std::string password);
        void			    setTopic(std::string topic);
        std::string		    getTopic();

        void 			    setOperator(int cl);
        std::vector<int>    getOperator();
		std::vector<Client> getChannelClients();
        void                addChannelClients(Client &ref);
        void    		    eraseChannelClients(int c);

        void    		    eraseOperator(int op);
        void   			    addOperator(int op);
        int                 areYouOperator(int cl);



};

#endif
