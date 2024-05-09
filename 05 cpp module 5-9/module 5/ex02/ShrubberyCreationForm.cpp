#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile(_target + "_shrubbery");
    outfile << "ASCII trees here 🌳🌲🌳" << std::endl;
    outfile.close();
}
