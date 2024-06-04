#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm( const std::string& target );
        ShrubberyCreationForm( const ShrubberyCreationForm& other );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
        ~ShrubberyCreationForm( void );

        void    execute( const Bureaucrat& executor ) const;
};