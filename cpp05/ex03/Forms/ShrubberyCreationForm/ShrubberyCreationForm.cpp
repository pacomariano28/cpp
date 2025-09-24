#include "ShrubberyCreationForm.hpp"
#include "../../Bureaucrat/Bureaucrat.hpp"
#include "../../Exceptions/GradeTooLowException.hpp"
#include <string>
#include <fstream>
#include <iostream>

// COF -----------------------------------------------------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm(void) 
	: AForm("ShrubberyCreationForm", 145, 137) {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) 
	: AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// METHODS -----------------------------------------------------------------------------------------------------------------

void			ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (!getIsSigned())
		throw FormNotSignedException();
		
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = getName() + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (file.is_open()) {
		file << "       _-_\n";
        file << "    /~~   ~~\\\n";
        file << " /~~         ~~\\\n";
        file << "{               }\n";
        file << " \\  _-     -_  /\n";
        file << "   ~  \\\\ //  ~\n";
        file << "_- -   | | _- _\n";
        file << "  _ -  | |   -_\n";
        file << "      // \\\\\n";
		file.close();
		 std::cout << "Shrubbery has been planted at " << filename << std::endl;
    } else {
        std::cout << "Error: Could not create file " << filename << std::endl;
	}
}