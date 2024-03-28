#include "Server.hpp"

void Server::info(int i)
{
    char buffer[1028] = {0};
    valread = 0;
    if ((valread = recv(clientArray[i].getSocketFd(), buffer, sizeof(buffer) - 1, 0)) <= 0) {
        quit(i);
        return;
    }
    buffer[valread] = '\0';
    std::string token, pass, user, nick;
    std::istringstream iss(buffer);
    while (iss >> token)
    {
        if (clientArray[i].getPassword().empty() && token == "PASS") 
        {
            iss >> pass;
            if (pass[0] == ':')
                pass = pass.substr(1);
            if (pass.compare(this->password))
            {
                sendFunct(clientArray[i].getSocketFd(), "wrong password\r\n");
                return;
            }
            clientArray[i].setPassword(pass);
        }
        else if (clientArray[i].getNickname().empty() && token == "NICK")
        {
            iss >> nick;
            if (isNicknameInUse(nick)) {
                sendFunct(clientArray[i].getSocketFd(), NICKNAME_IN_USE(nick));
                return;
            }
            else if (nick[0] == '#')
            {
                sendFunct(clientArray[i].getSocketFd(), "Your nickname can't contain '#' in the first index\r\n");
                return;    
            }
            clientArray[i].setNickname(nick);
        }
        else if (clientArray[i].getUsername().empty() && token == "USER") {
            iss >> user;
            clientArray[i].setUsername(user);
        }
    }
    if (!clientArray[i].getUsername().empty() && !clientArray[i].getNickname().empty() && !clientArray[i].getPassword().empty() && clientArray[i].getFlag() == 0)
        addClient(i);
}

void Server::running()
{
    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        
        max_sd = server_fd;
        for (int i = 0; i < (int)clientArray.size(); i++) {
            int clientSocket = clientArray[i].getSocketFd();
            if (clientSocket > 0) {
                FD_SET(clientSocket, &readfds);
                max_sd = std::max(max_sd, clientSocket);
            }
        }
        struct timeval timeout;
        timeout.tv_sec = 15;
        timeout.tv_usec = 0;
        this->activity = select(max_sd + 1, &readfds, NULL, NULL, &timeout);
        if ((activity < 0) && (errno != EINTR))
            perror("select error");
        if (FD_ISSET(server_fd, &readfds)) {
            newClient();
            connectToNewClient(new_socket);
        }
        for (int i = 0; i < (int)clientArray.size(); i++)
        {
            if (FD_ISSET(clientArray[i].getSocketFd(), &readfds)) 
            {
                if (clientArray[i].getFlag() == 0)
                    info(i);
                else
                    commands(i);               
            }
        }
    }
}
