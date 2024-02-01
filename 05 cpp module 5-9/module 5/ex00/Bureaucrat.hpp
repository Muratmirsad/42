/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:36:58 by mdiraga           #+#    #+#             */
/*   Updated: 2024/01/26 11:41:33 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw()
        {
            return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception
    {
        const char* what() const throw()
        {
            return "Grade is too low";
        }
    };

    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

private:
    const std::string name;
    int grade;

    void validateGrade(int grade);
};