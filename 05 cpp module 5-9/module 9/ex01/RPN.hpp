#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN {
public:
    RPN(const std::string& expression);
    ~RPN();
    int evaluate();

private:
    std::string expression;
    bool isOperator(const std::string& str);
    int performOperation(const std::string& op, int operand1, int operand2);
};
