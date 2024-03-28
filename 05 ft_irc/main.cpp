#include "Client.hpp"
#include "Server.hpp"

#include <iostream>

int err (std::string str) {
    std::cout << str << std::endl;
    return (1);
}

int main(int ac, char **av) {

    if (ac != 3) 
        return (err("Not enough parameters!"));

    Server server;
    if (server.start(av[1], av[2]))
        return (err("Wrong port!"));
    server.createSocket();
    server.running();
}