#include "PmergeMe/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <climits>
#include <deque>
#include <list>



static bool parseValues(int n) {
	if (n < 0)
		throw std::runtime_error("Error: negative number");

	if (n < 0)
		throw NegativeNumber();
}


int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << E_DIFF_PARAMS << std::endl;
		return EXIT_FAILURE;
	}

	try {
		checkNegative();
		checkLimits();

		
	} catch (NegativeNumber& e) {
		std::cout << e.what() << std::endl;
	} catch (OutOfRange& e){
		std::cout << e.what() << std::endl;
	}


	return 0;
}