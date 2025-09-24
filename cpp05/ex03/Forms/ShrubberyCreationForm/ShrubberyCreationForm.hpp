#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "../../AForm/AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& name);
		ShrubberyCreationForm(ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void			execute(const Bureaucrat & executor) const;
};

#endif