#include "PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <sstream>


int main(int ac, char **av) {

	try {
		
		PmergeMe sorter(ac, av);
		sorter.run();

	} catch ( const DiffParams& e ) {
		std::cerr << e.what() << std::endl;
	}
	catch ( const NegativeNumber& e ) {
		std::cerr << e.what() << std::endl;
	}
	catch ( const OutOfRange& e ) {
		std::cerr << e.what() << std::endl;
	}
	catch ( const InvalidNumber& e ) {
		std::cerr << e.what() << std::endl;
	}
	catch ( const PmergeMeException& e ) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}