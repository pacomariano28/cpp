#include "PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <sstream>

/*

1. ✅ Parsing y validación
2. ⏭️ Implementar Ford-Johnson para std::vector
3. ⏭️ Implementar Ford-Johnson para std::deque
4. ⏭️ Medir tiempos de ejecución
5. ⏭️ Mostrar resultados

*/


int main(int ac, char **av) {

	try {
		PmergeMe sorter(ac, av);
		sorter.run();
	} catch (const PmergeMeException& e) {
		std::cerr << e.what() << std::endl;
	}



	return 0;
}