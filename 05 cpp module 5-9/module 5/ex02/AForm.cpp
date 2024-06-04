#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed!";
};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
			: name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
    return name;
}

bool AForm::isSigned() const
{
    return signedStatus;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), signedStatus(other.signedStatus),
		 		gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{

}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
	{
        signedStatus = other.signedStatus;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() << " | Signed: " << (form.isSigned() ? "Yes" : "No")
       << " | Grade Required to Sign: " << form.getGradeToSign()
       << " | Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
