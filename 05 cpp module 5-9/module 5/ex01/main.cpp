#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 25);

        Form taxForm("Tax Form", 30, 40);

        std::cout << "Before signing:\n" << taxForm << std::endl << std::endl;

        alice.signForm(taxForm);
        std::cout << "After Alice's attempt to sign:\n" << taxForm << std::endl << std::endl;

        bob.signForm(taxForm);
        std::cout << "After Bob's attempt to sign:\n" << taxForm << std::endl << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
