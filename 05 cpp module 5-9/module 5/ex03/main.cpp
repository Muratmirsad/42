#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try
    {
        Intern  intern;

        AForm *form = intern.makeForm("shrubbery creation", "test1");

        Bureaucrat david("David", 120);
    
        david.executeForm(*form);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    return 0;
}
