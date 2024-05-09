#ifndef FORMNOTSIGNEDEXCEPTION_HPP
#define FORMNOTSIGNEDEXCEPTION_HPP

#include <exception>
#include <string>

class FormNotSignedException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Form is not signed and cannot be executed.";
    }
};

#endif
