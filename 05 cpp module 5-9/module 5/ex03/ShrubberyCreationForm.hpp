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

        static  AForm* createShrubberyCreationForm(std::string const &target);

        void    execute( const Bureaucrat& executor ) const;
};