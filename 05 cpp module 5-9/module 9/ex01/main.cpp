#include "RPN.hpp"
#include <iostream>

int main(int argc, char** av) {
    if (argc != 2) {
        std::cerr << "Usage: ./eval_expr expression" << std::endl;
        return 1;
    }

    std::string expression(av[1]);
    RPN rpn(expression);
    int result = rpn.evaluate();
    std::cout << result << std::endl;

    return 0;
}