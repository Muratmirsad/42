#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <arpa/inet.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

class Client {
    private:
        std::string nickname;
        std::string username;
        std::string realName;
        std::string host;
        std::string password;
        int         socket_fd;
        int     flag;

    public:
        Client();
        ~Client();
        void setNickname(std::string _nickname);
        void setUsername(std::string _username);
        void setPassword(std::string _password);
        void setRealName(std::string _realName);
        void setHost(std::string _host);

        std::string getNickname();
        std::string getUsername();
        std::string getRealName();
        std::string getHost();
        std::string getPassword();

        void setSocketFd(int i);
        int getSocketFd();
        int getFlag();
        void setFlag(int i);
};


#endif