#include "Server.hpp"

int Server::start(char *av1, char *av2) {
    int i = 0;
    while (av1[i])
    {
        if (!(av1[i] >= 48 && av1[i] <= 57))
            return(1);
        i++;
    }
    port = atoi(av1);
    if (!(port >= 0 && port <= 65535)) // 0 değişebilir
        return (1);
    
    this->password = av2;
    
    char str_h[256];
    gethostname(str_h, sizeof(str_h));
    
    std::string _h(str_h);
    this->setHostname(_h);
    return (0);
}

void    Server::createSocket() {
    addrlen = sizeof(address);
    opt = 1;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        std::cerr << "socket failed" << std::endl;
        exit(EXIT_FAILURE); 
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0){
        std::cerr << "setsockopt" << std::endl;;
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    int flags = fcntl(server_fd, F_GETFL, 0);
    if (flags == -1) {
        std::cerr << "ERROR getting socket flags" << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    if (fcntl(server_fd, F_SETFL, O_NONBLOCK) == -1) {
        std::cerr << "ERROR setting socket to non-blocking mode" << std::endl;
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    std::cout << "Socket set to non-blocking mode successfully" << std::endl;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        std::cerr << "bind failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 10) < 0){
        std::cerr << "listen" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::newClient() {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

void Server::connectToNewClient(int n_socket) {
    clientArray.push_back(Client());
    clientArray[clientArray.size() - 1].setSocketFd(n_socket);
    sendFunct(n_socket, "Please enter server pass, your user and nickname: PASS <pass_supplied_by_the_server> / USER <your user>  /  NICK <your nick>\r\n");
}


void Server::addClient(int i) 
{
    sendFunct(clientArray[i].getSocketFd(), LOGIN(clientArray[i].getNickname(), clientArray[i].getUsername()));
    clientArray[i].setFlag(10);
}
