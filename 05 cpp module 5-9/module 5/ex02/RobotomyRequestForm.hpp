#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "FormNotSignedException.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

public:
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm() {}

    void execute(const Bureaucrat& executor) const;
};

#endif
