#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "FormNotSignedException.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

public:
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm() {}

    void execute(const Bureaucrat& executor) const;
};

#endif
