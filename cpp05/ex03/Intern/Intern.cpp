#include <iostream>
#include <cctype>
#include "Intern.hpp"
#include "../AForm/AForm.hpp"
#include "../Forms/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../Forms/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../Forms/PresidentialPardonForm/PresidentialPardonForm.hpp"

// COF ---------------------------------------------------------------------------------------------------------------------

	Intern::Intern(void) {}

/* 	Intern::Intern(const Intern& other) : Intern() {
		(void)other;
	} */

	Intern& Intern::operator=(const Intern& other) {
		(void)other;
		return *this;
	}

	Intern::~Intern(void) {}

// PRIVATE METHODS ---------------------------------------------------------------------------------------------------------------------

AForm* Intern::createShrubberyForm(const std::string& target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target){
	return new PresidentialPardonForm(target);
}


// PUBLIC METHODS ---------------------------------------------------------------------------------------------------------------------

AForm*	Intern::makeForm(const std::string formName, const std::string target) {
	
	std::string lowerFormName = formName;
	for (size_t i = 0; i < lowerFormName.length(); i++) {
        lowerFormName[i] = ::tolower(lowerFormName[i]);
    }

	FormInfo forms[] = {
		{"shrubbery creation", &Intern::createShrubberyForm}, 
		{"robotomy request", &Intern::createRobotomyForm}, 
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for(int i = 0; i < 3; i++) {
		if (forms[i].name == lowerFormName) {
			std::cout << "Intern creates " << lowerFormName << std::endl;
			return (this->*forms[i].creator)(target); 
		}
	}

	std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
    return NULL;
}