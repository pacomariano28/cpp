#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"

int main() {

    Bureaucrat bob("Bob", 56);

	try {
		AForm contract("TopSecret", 55, 30);

    	std::cout << bob << std::endl;
    	std::cout << contract << std::endl;

    	bob.signAForm(contract);

    	bob.incrementGrade();

    	bob.signAForm(contract);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return 0;
}