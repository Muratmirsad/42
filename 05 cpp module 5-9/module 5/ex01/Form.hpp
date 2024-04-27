#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {
private:
    const std::string	name;
    bool				signedStatus;
    const int			gradeToSign;
    const int			gradeToExecute;

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
    ~Form();

    Form& operator=(const Form& other);
    friend std::ostream& operator<<(std::ostream& os, const Form& form);

    std::string	getName() const;
    bool		isSigned() const;
    int			getGradeToSign() const;
    int			getGradeToExecute() const;
    void		beSigned(const Bureaucrat& bureaucrat);
};

#endif
