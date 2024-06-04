#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::srand(std::time(0));
    int randomİnt = std::rand() % 2;

    std::cout << "Dididididididi..." << std::endl;

    if (randomİnt)
    {
        std::cout << "Drilling was successful!" << std::endl;
    }
    else
    {
        std::cout << "Drilling was unsuccessful!" << std::endl;
    }
}

