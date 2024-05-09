#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "FormNotSignedException.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;

public:
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm() {}

    void execute(const Bureaucrat& executor) const;
};

#endif
