#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	__name;
		bool				__isSigned;
		const int			__gradeToSign;
		const int			__gradeToExecute;

	public:
		Form(void);
		Form(const std::string name, const int gradeToSign, const int gradeToExectute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		const std::string&	getName (void) const;
		const int&			getGradeToSign (void) const;
		const int&			getGradeToExecute (void) const;
		void				beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, const Form& b);

#endif