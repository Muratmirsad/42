#include "RPN.hpp"

RPN::RPN(const std::string& expression) : expression(expression) {}
RPN::~RPN() {}

bool RPN::isOperator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

int RPN::performOperation(const std::string& op, int operand1, int operand2) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") {
        if (operand2 == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            exit(1);
        }
        return operand1 / operand2;
    }
    return 0; // Geçersiz operatör
}

int RPN::evaluate() {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                std::cerr << "Error: Insufficient operands" << std::endl;
                exit(1);
            }
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            int result = performOperation(token, operand1, operand2);
            stack.push(result);
        } else {
            try {
                int operand = std::stoi(token);
                stack.push(operand);
            } catch (const std::exception& e) {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        exit(1);
    }

    return stack.top();
}