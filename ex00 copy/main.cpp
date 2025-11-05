#include "BitcoinExchange/BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {

	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	try {

		BitcoinExchange btc(av[1]);

	} catch(const DB_BadInput& e) {
        std::cerr << e.what() << std::endl;
        return (1);
		
    } catch(const DB_NotOpen& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

	return 0;
}