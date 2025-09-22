#include "Form.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

Form::Form(void) : __name("Undefined"), __isSigned(false), __gradeToSign(100), __gradeToExecute(20) {
    std::cout << "Form " << __name << " created." << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) 
    : __name(name) , __isSigned(false), __gradeToSign(validateGrade(gradeToSign)), __gradeToExecute(validateGrade(gradeToExecute)) {}

Form::Form(const Form& other) 
    : __name(other.__name), __isSigned(other.__isSigned), __gradeToSign(other.__gradeToSign), __gradeToExecute(other.__gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        __isSigned = other.__isSigned;
    return *this;
}

Form::~Form(void) {
    std::cout << "Form " << __name << " destroyed." << std::endl;
}

// --------------------------------------------------------------------------------------------------

const std::string& Form::getName(void) const {
    return __name;
}

const int& Form::getGradeToSign (void) const {
    return __gradeToSign;
}

const int& Form::getGradeToExecute (void) const {
    return __gradeToExecute;
}

void		Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= __gradeToSign)
        __isSigned = true;
    else
        throw GradeTooLowException();
}

// --------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() << " , form created with min " << f.getGradeToSign() << " grade to sign.";
    return out;
}