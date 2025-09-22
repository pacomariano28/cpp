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

		static	int	validateGrade(int grade) {
			if (grade < 1)
				throw GradeTooHighException();

			if (grade > 150)
				throw GradeTooLowException();
			
			return grade;
		}

	public:
		Bureaucrat(void) : __name("Rookie") , __grade(150) {}

		Bureaucrat(const std::string name, const int grade) 
			: __name(name) , __grade(validateGrade(grade)) {}

		Bureaucrat(const Bureaucrat &other) : __name(other.__name) , __grade(other.__grade) {}

		Bureaucrat& operator=(const Bureaucrat &other) {
			if (this != &other)
				__grade = other.__grade;
			return *this;
		}

		~Bureaucrat(void) {};

		// -------------------------------------------------------

		const std::string&	getName(void) const { return __name; }

		int getGrade(void) const { return __grade; }

		void incrementGrade(void) {
			if (__grade <= 1)
				throw GradeTooHighException();
			--__grade;
		}

		void decrementGrade(void) {
			if (__grade >= 150)
				throw GradeTooLowException();
			++__grade;
		}
};

inline std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << " , bureaucrat grade " << b.getGrade();
	return out;
}

#endif