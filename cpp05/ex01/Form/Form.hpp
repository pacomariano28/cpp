#ifndef AForm_HPP
#define AForm_HPP

#include <string>

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
		~AForm(void);

		const std::string&	getName (void) const;
		const int&			getGradeToSign (void) const;
		const int&			getGradeToExecute (void) const;
		void				beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& out, const AForm& b);

#endif