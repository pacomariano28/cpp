#include "AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"
#include "../Exceptions/GradeTooLowException.hpp"
#include "../Exceptions/GradeTooHighException.hpp"

// COF -------------------------------------------------------------------------------------------

AForm::AForm(void) : __name("Undefined"), __isSigned(false), __gradeToSign(100), __gradeToExecute(20) {
    std::cout << "AForm " << __name << " created." << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) 
    : __name(name) , __isSigned(false), __gradeToSign(validateGrade(gradeToSign)), __gradeToExecute(validateGrade(gradeToExecute)) {}

AForm::AForm(const AForm& other) 
    : __name(other.__name), __isSigned(other.__isSigned), __gradeToSign(other.__gradeToSign), __gradeToExecute(other.__gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        __isSigned = other.__isSigned;
    return *this;
}

AForm::~AForm(void) {
    std::cout << "AForm " << __name << " destroyed." << std::endl;
}

// GETTERS -------------------------------------------------------------------------------------------

const 	std::string& AForm::getName(void) const {
    return __name;
}

int		AForm::getGradeToSign (void) const {
    return __gradeToSign;
}

int		AForm::getGradeToExecute (void) const {
    return __gradeToExecute;
}

//  METHODS -----------------------------------------------------------------------------------

void		AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= __gradeToSign)
        __isSigned = true;
    else
        throw GradeTooLowException();
}


bool		AForm::getIsSigned() const {
	return __isSigned;
}

// FUNCTIONS ------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form: " << f.getName()
        << " | Signed: " << (f.getIsSigned() ? "yes" : "no")
        << " | Grade to sign: " << f.getGradeToSign()
        << " | Grade to execute: " << f.getGradeToExecute();
    return out;
}
