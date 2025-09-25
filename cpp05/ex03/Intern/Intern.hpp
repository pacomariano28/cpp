#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
	private:
		struct FormInfo {
        	std::string name;
			AForm* (Intern::*creator)(const std::string& target);
		};

		AForm* createShrubberyForm(const std::string& target);
		AForm* createRobotomyForm(const std::string& target);
		AForm* createPresidentialForm(const std::string& target);

	public:
		Intern(void);
		Intern(const Intern& other); // no tienen mucho sentido pero bueno
		Intern& operator=(const Intern& other); // no tienen mucho sentido pero bueno
		~Intern(void);

		AForm*	makeForm(const std::string formName, const std::string target);
};

#endif