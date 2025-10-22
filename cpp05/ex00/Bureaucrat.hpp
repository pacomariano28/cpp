#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Exceptions/GradeTooLowException.hpp"
#include "Exceptions/GradeTooHighException.hpp"

class Bureaucrat {
	private:
		const std::string	__name;
		int					__grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const char* str, const int grade);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		// -------------------------------------------------------

		const std::string&	getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif