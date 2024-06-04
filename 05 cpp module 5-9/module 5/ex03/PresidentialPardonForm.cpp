#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    (void)rhs;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::createPresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}