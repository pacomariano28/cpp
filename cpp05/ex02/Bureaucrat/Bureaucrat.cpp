#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : __name("Rookie") , __grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : __name(name) , __grade(validateGrade(grade)) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : __name(other.__name) , __grade(other.__grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
			if (this != &other)
				__grade = other.__grade;
			return *this;
}

Bureaucrat::~Bureaucrat(void) {};

// GETTERS ------------------------------------------------------------------------------------------------------

const std::string&	Bureaucrat::getName(void) const { 
	return __name; 
}

int					Bureaucrat::getGrade(void) const { 
	return __grade; 
}

// METHODS ------------------------------------------------------------------------------------------------------

void				Bureaucrat::incrementGrade(void) {
	if (__grade <= 1)
		throw GradeTooHighException();
	--__grade;
}

void				Bureaucrat::decrementGrade(void) {
	if (__grade >= 150)
		throw GradeTooLowException();
	++__grade;
}

void				Bureaucrat::signAForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << __name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << __name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

// FUNCTIONS -----------------------------------------------------------------------------------------------------

int					validateGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();

	if (grade > 150)
		throw GradeTooLowException();
	
	return grade;
}

std::ostream&		operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << " , bureaucrat grade " << b.getGrade();
	return out;
}

