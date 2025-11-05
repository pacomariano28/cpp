#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc(av[1]);	
	} catch ( IN_NotOpen& e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}