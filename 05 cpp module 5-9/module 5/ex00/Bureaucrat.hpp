#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
			GradeTooHighException() throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
			GradeTooLowException() throw();
		};

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat&	operator=(const Bureaucrat& other);

		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade();
		void		decrementGrade();

		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
};

#endif
