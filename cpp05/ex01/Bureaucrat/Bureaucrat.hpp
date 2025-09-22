#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "../Form/Form.hpp"
#include "../Exceptions/GradeTooLowException.hpp"
#include "../Exceptions/GradeTooHighException.hpp"

class Bureaucrat {
	private:
		const std::string	__name;
		int					__grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		// -------------------------------------------------------

		const std::string&	getName(void) const;
		int 				getGrade(void) const;
		void 				incrementGrade(void);
		void 				decrementGrade(void);
		void				signForm(Form& f);
};

// ---------------------------------------------------------------

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& b);
int				validateGrade(int grade);

#endif