#include "Intern.hpp"
#include "../AForm/AForm.hpp"
#include "../Forms/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../Forms/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../Forms/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

// COF ---------------------------------------------------------------------------------------------------------------------

	Intern::Intern(void) {}

	Intern::Intern(const Intern& other) : Intern() {
		(void)other;
	}
	
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
	std::transform(lowerFormName.begin(), lowerFormName.end(), lowerFormName.begin(), ::tolower);

	FormInfo forms[] = {
		{"shrubbery creation", &Intern::createShrubberyForm}, 
		{"robotomy request", &Intern::createRobotomyForm}, 
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for(int i = 0; i < 3; i++) {
		if (forms[i].name == lowerFormName) {
			std::cout << "Intern creates " << lowerFormName << std::endl;
			return forms[i].creator(target); 
		}
	}

	std::cout << "Error: Form '" << formName << "' does not exist" << std::endl;
    return NULL;
}