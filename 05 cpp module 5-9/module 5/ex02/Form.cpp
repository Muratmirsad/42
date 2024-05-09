#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
			: name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{

}

std::string Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), signedStatus(other.signedStatus),
		 		gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
	{
        signedStatus = other.signedStatus;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << " | Signed: " << (form.isSigned() ? "Yes" : "No")
       << " | Grade Required to Sign: " << form.getGradeToSign()
       << " | Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
