#include <cstdlib>
#include <iostream>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "../../Bureaucrat/Bureaucrat.hpp"
#include "../../Exceptions/GradeTooLowException.hpp"

// COF -----------------------------------------------------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm(void) 
	: AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// METHODS -----------------------------------------------------------------------------------------------------------------

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
	
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::srand(std::time(0));
	std::cout << "*BZZZZT* Drilling sounds..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << "Robotomy successful!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
