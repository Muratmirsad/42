#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << " | Signed: " << (form.isSigned() ? "Yes" : "No")
       << " | Grade Required to Sign: " << form.getGradeToSign()
       << " | Grade Required to Execute: " << form.getGradeToExecute();
    return os;
}
