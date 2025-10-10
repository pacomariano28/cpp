#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(std::string& inputFile) {
	try {
		loadData(BITCOIN_DB, DDBB_FILE, _rates);
		loadData(inputFile.c_str(), INPUT_FILE, _input);
	} catch(std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

BitcoinExchange::~BitcoinExchange(void) {}

// METHODS ------------------------------------------------------------------------------------

static bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < 4; ++i)
        if (!isdigit(yearStr[i])) return false;
    for (size_t i = 0; i < 2; ++i)
        if (!isdigit(monthStr[i]) || !isdigit(dayStr[i])) return false;

    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

/* static bool isValidValue(float value) {
	return (value >= 0 && value <= 1000);
} */

void	BitcoinExchange::loadData(const char* file, FileType type, std::map<std::string, float>& container) {
	std::ifstream fileStream(file);

	if (!fileStream.is_open())
		throw std::runtime_error("Error: not possible to open the file");
	
	std::string line;
	std::string	date;
	double		value;

	std::getline(fileStream, line);

	while(std::getline(fileStream, line)) {
		size_t pos = line.find(type);

		if (pos == std::string::npos)
			throw std::runtime_error("Error: bad format in database line: " + line);

		date = line.substr(0, pos);
		
		// Eliminar espacios al principio
		while (!date.empty() && (date[0] == ' ' || date[0] == '\t'))
			date.erase(0, 1);
		
		// Eliminar espacios al final
		while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
			date.erase(date.size() - 1, 1);

		value 	= atof(line.substr(pos + 1).c_str());

		if (!isValidDate(date))
			throw std::runtime_error("Error: no valid date format on database line: " + line);

		// el problema que tengo ahora es que si falla leyendo el input sigue, no tiene que hacer throw.
		if ((type == INPUT_FILE && value > 1000) && (value == 0 )
			throw std::runtime_error("Error: no valid btc value on database line " + line);

		container[date] = value;
	}

	    std::map<std::string, float>::const_iterator it = _rates.begin();
		while (it != _rates.end()) {
			std::cout << it->first << " => " << it->second << std::endl;
			++it;
		}
}