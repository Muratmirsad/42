#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    virtual ~AForm() {}

    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(const Bureaucrat& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
