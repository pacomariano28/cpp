#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "../../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm(void);

		void	execute(const Bureaucrat &executor) const;
};

#endif