#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!isSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outfile(target + "_shrubbery");
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    outfile << "ASCII tree here: \U0001F332";

    outfile.close();
}

AForm* ShrubberyCreationForm::createShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}