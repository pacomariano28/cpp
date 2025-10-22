#include "Bureaucrat.hpp"

int main() {

	std::cout << "\n" << std::endl;
	Bureaucrat manolo(NULL, 150);
    try {
        Bureaucrat rookie; // default
        Bureaucrat john("John", 42); // personalizado
        Bureaucrat boss("Boss", 1); // límite alto
        Bureaucrat trainee("Trainee", 150); // límite bajo

        std::cout << rookie << std::endl;
        std::cout << john << std::endl;
        std::cout << boss << std::endl;
        std::cout << trainee << std::endl;

        // Intento de grado inválido para lanzar excepción
        Bureaucrat invalid("BadGuy", 0);
    } catch (std::exception &e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

	std::cout << "\n" << std::endl;

	try {
        Bureaucrat top("Top", 1);
        top.incrementGrade(); // debería lanzar GradeTooHighException
    } catch (std::exception &e) {
        std::cout << "Excepción al incrementar: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementGrade(); // debería lanzar GradeTooLowException
    } catch (std::exception &e) {
        std::cout << "Excepción al decrementar: " << e.what() << std::endl;
    }

	std::cout << "\n" << std::endl;

	Bureaucrat jane("Jane", 75);
    std::cout << jane << std::endl;

    jane.incrementGrade();
    std::cout << "Después de incrementar: " << jane << std::endl;

    jane.decrementGrade();
    std::cout << "Después de decrementar: " << jane << std::endl;


	std::cout << "\n" << std::endl;
}
