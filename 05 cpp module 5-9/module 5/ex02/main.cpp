#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat alice("Alice", 23);
        Bureaucrat bob("Bob", 25);


        AForm taxForm("Tax Form", 25, 40);

        std::cout << "Before signing:\n" << taxForm << std::endl << std::endl;

        alice.signForm(taxForm);
        std::cout << "After Alice's attempt to sign:\n" << taxForm << std::endl << std::endl;

        bob.signForm(taxForm);
        std::cout << "After Bob's attempt to sign:\n" << taxForm << std::endl << std::endl;


        Bureaucrat david("David", 120);
        ShrubberyCreationForm a("testa");
    
        a.beSigned(david);
        a.execute(david);


        Bureaucrat elise("Elise", 30);
        RobotomyRequestForm b("testb");
    
        b.beSigned(elise);
        b.execute(elise);


        std::cout << std::endl;


        Bureaucrat violet("Violet", 2);
        PresidentialPardonForm c("testc");
    
        c.beSigned(violet);
        c.execute(violet);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    return 0;
}
