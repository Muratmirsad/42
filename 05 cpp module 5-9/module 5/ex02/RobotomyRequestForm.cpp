#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // For rand

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "* Drill noises *\n";
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!\n";
    } else {
        std::cout << "Robotomy on " << _target << " failed.\n";
    }
}
