#include "PmergeMe/PmergeMe.hpp"
#include "Exceptions/PmergeMeExceptions.hpp"
#include <iostream>
#include <sstream>
#include <climits>


int main(int ac, char **av) {

	try {
		PmergeMe sorter(ac, av);
		//sorter.run()
	} catch (const PmergeMeException& e) {
		std::cerr << e.what() << std::endl;
	}



	return 0;
}