#include "PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <sstream>


int main(int ac, char **av) {

	try {
		PmergeMe sorter(ac, av);
		sorter.run();
	} catch (const PmergeMeException& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}