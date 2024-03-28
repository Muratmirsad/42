#pragma once

#include <fcntl.h>
#include "Messages.hpp"
#include "Client.hpp"
#include "Channel.hpp"

class Server {
    private:
        std::string hostname;
        std::string password;
        int         port;
        int         server_fd;
        int         new_socket;
        int         activity;
        int         max_sd;
        int         valread;
        int         opt;
        socklen_t addrlen;
        struct sockaddr_in address;
        std::vector<Client> clientArray;
        std::vector<Channel> channelArray;
        
    public:
        void        connectToNewClient(int n_socket);
        void        info(int i);
        void        running();
        int         isNicknameInUse(std::string _nick);
        void        commands(int i);
        void        join(int i, std::string channelName, std::string channelPass);
        void        part(int i, std::string channelName);

        std::string getHostname();
        void        setHostname(std::string _host);
        int         start(char *av1, char *av2);
        void        createSocket();

        void        newClient();
        void        addClient(int i);
        void        sendFunct(int fd, std::string raw);
        int         whichChannel(std::string channelName);
        void        quit(int i);
        int         findIndex(std::string nick);

        void        who(int i, std::string token1);
        void        mode(int i, std::string token1, std::string token2);
        void        list(int i);
        void        topic(int i, std::string channelName, std::string topicMessage);
        void        kick(int i, std::string channelName, std::string clientNick);
        void        mess(int p, std::string channelOrClient, std::string buffer);
        int         areYouIn(int cl, int ch);

};

