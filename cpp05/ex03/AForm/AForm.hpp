#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	__name;
		bool				__isSigned;
		const int			__gradeToSign;
		const int			__gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExectute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm(void);

		const 	std::string&	getName (void) const;
		int						getGradeToSign (void) const;
		int						getGradeToExecute (void) const;
		bool					getIsSigned() const;

		void					beSigned(const Bureaucrat& b);
		virtual void			execute(Bureaucrat const & executor) const = 0;


	class FormNotSignedException : public std::exception {
		public:
			virtual const char*	what() const throw() {
				return "Form not signed!";
			}
	};

};

std::ostream&	operator<<(std::ostream& out, const AForm& b);

#endif