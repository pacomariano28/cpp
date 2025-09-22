#include "Bureaucrat/Bureaucrat.hpp"
#include "Form/Form.hpp"

int main() {

    Bureaucrat bob("Bob", 56);

	try {
		Form contract("TopSecret", 55, 30);

    	std::cout << bob << std::endl;
    	std::cout << contract << std::endl;	

    	bob.signForm(contract);

    	bob.incrementGrade();

    	bob.signForm(contract);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Ya no hace core dumped" << std::endl;
    return 0;
}