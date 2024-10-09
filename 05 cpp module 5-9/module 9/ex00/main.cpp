#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc input.txt" << std::endl;
        exit(-1);
    }

    BitcoinExchange btc(av[1]);
}