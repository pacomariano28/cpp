#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
	private:
		static AForm* createShrubberyForm(const std::string& target);
		static AForm* createRobotomyForm(const std::string& target);
		static AForm* createPresidentialForm(const std::string& target);

		struct FormInfo {
        	std::string name;
			AForm* (*creator)(const std::string& target);
		};

	public:
		Intern(void);
		Intern(const Intern& other); // no tienen mucho sentido pero bueno
		Intern& operator=(const Intern& other); // no tienen mucho sentido pero bueno
		~Intern(void);

		AForm*	makeForm(const std::string formName, const std::string target);
};

#endif