#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "../../AForm/AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm(void);

		void	execute(const Bureaucrat &executor) const;
};

#endif