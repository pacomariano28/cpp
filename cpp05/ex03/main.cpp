#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"
#include "Forms/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Forms/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Forms/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Intern/Intern.hpp"
#include "Exceptions/GradeTooHighException.hpp"
#include "Exceptions/GradeTooLowException.hpp"
#include <iostream>

int main(void) {
    try {
        Intern intern;

        AForm* presidential = intern.makeForm("presidential pardon", "norminette");
        Bureaucrat example("antonimo", 5);
        std::cout << std::endl;

        presidential->beSigned(example);
        std::cout << std::endl;

        presidential->execute(example);
        std::cout << std::endl;

        delete presidential;

    } catch (AForm::FormNotSignedException& e) {
        std::cout << "AForm Error: " << e.what() << std::endl;
        return 1;
    } catch (GradeTooHighException& e) {
        std::cout << "GradeTooHighException: " << e.what() << std::endl;
        return 1;
    } catch (GradeTooLowException& e) {
        std::cout << "GradeTooLowException: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}