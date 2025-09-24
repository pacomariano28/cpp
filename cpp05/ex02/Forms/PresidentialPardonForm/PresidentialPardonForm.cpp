#include "PresidentialPardonForm.hpp"
#include "../../Bureaucrat/Bureaucrat.hpp"
#include "../../Exceptions/GradeTooLowException.hpp"

// COF -----------------------------------------------------------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm(void) 
	: AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
	: AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

// METHODS -----------------------------------------------------------------------------------------------------------------

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}