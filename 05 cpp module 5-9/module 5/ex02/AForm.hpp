#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm {
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

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
    ~AForm();

    AForm& operator=(const AForm& other);
    friend std::ostream& operator<<(std::ostream& os, const AForm& form);

    std::string	getName() const;
    bool		isSigned() const;
    int			getGradeToSign() const;
    int			getGradeToExecute() const;
    void		beSigned(const Bureaucrat& bureaucrat);
};

#endif
