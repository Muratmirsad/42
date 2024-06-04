#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*createFunctions[3])(std::string const &) = {
        &ShrubberyCreationForm::createShrubberyCreationForm, 
        &RobotomyRequestForm::createRobotomyRequestForm, 
        &PresidentialPardonForm::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return createFunctions[i](target);
        }
    }

    std::cout << "Error: Invalid form type." << std::endl;
    return NULL;
}
