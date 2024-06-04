#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string const _target;

    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        static  AForm* createPresidentialPardonForm(std::string const &target);

        void    execute(Bureaucrat const &executor) const;
};
