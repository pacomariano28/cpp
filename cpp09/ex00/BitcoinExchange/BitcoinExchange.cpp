#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>


BitcoinExchange::BitcoinExchange(char *inputFile) {
	try {
		loadData(BITCOIN_DB);
		
	} catch(std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

BitcoinExchange::~BitcoinExchange(void) {}

// METHODS ------------------------------------------------------------------------------------

void	BitcoinExchange::loadData(char* DBFile) {
	std::ifstream file(DBFile);

	if (!file.is_open())
		throw std::runtime_error("Error: not possible to open the file");
	
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		size_t pos = line.find(',');

		if (pos == std::string::npos)
			throw std::runtime_error("Error: bad format in database line: " + line);

		std::string	date	= line.substr(0, pos);
		double		value	= std::atof(line.substr(pos, line.length()).c_str());

	}
}