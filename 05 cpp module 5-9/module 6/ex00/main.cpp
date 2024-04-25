#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "please enter one argument" << std::endl;
        return (1);
    }

    ScalarConverter::convert(av[1]);

    return (0);
}
