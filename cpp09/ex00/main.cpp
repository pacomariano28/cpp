#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	BitcoinExchange btc(av[1]);

	return 0;
}