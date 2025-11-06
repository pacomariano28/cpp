#include "BitcoinExchange.hpp"
#include "../Exceptions.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstddef>

// CONSTANTS
static const float 	MAX_VALUE = 1000.0f;

static const int 	MIN_MONTH = 1;
static const int 	MAX_MONTH = 12;
static const int 	MIN_DAY = 1;
static const int 	MAX_DAY = 31;

static const size_t YEAR_POS = 0;
static const size_t YEAR_LENGTH = 4;
static const size_t MONTH_POS = 5;
static const size_t MONTH_LENGTH = 2;
static const size_t DAY_POS = 8;
static const size_t DAY_LENGTH = 2;
static const size_t DATE_LENGTH = 10;



BitcoinExchange::BitcoinExchange(const std::string& inputFile) {
	loadDatabase();
	processInput(inputFile);
}

BitcoinExchange::~BitcoinExchange(void) {}


// HELPER FUNCTIONS ------------------------------------------------------------------------------------

static bool isDateInRange(const Date& date) {
    if (date.year < 2009 || date.year > 2025)
        return false;
    if (date.month < MIN_MONTH || date.month > MAX_MONTH)
        return false;
    if (date.day < MIN_DAY)
        return false;

    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0))
        days_in_month[1] = 29;
    if (date.day > days_in_month[date.month - 1])
        return false;

    return true;
}

static bool isHeaderLine(const std::string& line) {
	
	std::istringstream iss(line);
	std::string cleanLine;
	std::string word;

	while (iss >> word)
		cleanLine += word;
	
	return (cleanLine == "date|value");
}

// METHODS ------------------------------------------------------------------------------------

void BitcoinExchange::findRate(const Line& parsedLine) {
	
	std::map<std::string, float>::iterator it = _rates.lower_bound(parsedLine.date.dateStr);
	if (it == _rates.end() || it->first != parsedLine.date.dateStr) {
		if (it != _rates.begin())
			--it;
	}
	float rate = it->second;
	float result = parsedLine.value * rate;
	std::cout << parsedLine.date.dateStr << " => " << parsedLine.value << " = " << result << std::endl;
}

float BitcoinExchange::getValue(const std::string& valueStr, Type type) {
    
	if (valueStr.empty())
        throw IN_EmptyValue();

	char* endPtr;
	float value = std::strtof(valueStr.c_str(), &endPtr);
    
	if (*endPtr != '\0')
		throw IN_NotNumericValue();

	if (value < 0)
		throw IN_NotPositiveNumber();

	if (type == INPUT && value > MAX_VALUE)
		throw IN_OutOfRange();

    return value;
}

Date BitcoinExchange::getDate(const std::string& dateStr) {
    
	if (dateStr.length() != DATE_LENGTH || dateStr[4] != '-' || dateStr[7] != '-')
		throw IN_BadDate();

	Date date;

    date.day 	= std::atoi(dateStr.substr(DAY_POS, DAY_LENGTH).c_str());
    date.month 	= std::atoi(dateStr.substr(MONTH_POS, MONTH_LENGTH).c_str());
	date.year 	= std::atoi(dateStr.substr(YEAR_POS, YEAR_LENGTH).c_str());
	date.dateStr = dateStr;

	if (!isDateInRange(date))
		throw IN_BadDate();

	return date;

}

Line BitcoinExchange::parseLine(const std::string& line, Type type) {
	
	std::istringstream 	iss(line);

	std::string			cleanLine;
	std::string			word;

	while  (iss >> word)
		cleanLine += word;

	size_t separator = cleanLine.find((type == DB) ? ',' : '|');

	if (separator == std::string::npos)
		throw IN_NoSeparator();

	Line parsedLine;
	parsedLine.date 	= getDate(cleanLine.substr(0, separator));
	parsedLine.value 	= getValue(cleanLine.substr(separator + 1), type);

	return parsedLine;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
	
	std::ifstream fileStream(inputFile.c_str());
	if (!fileStream.is_open())
		throw IN_NotOpen();

	std::string line;

	while (std::getline(fileStream, line)) {

		if (line.empty() || isHeaderLine(line))
			continue ;

		try {

			Line parsedLine = parseLine(line, INPUT);
			findRate(parsedLine);

		} catch ( IN_BadDate& e ) {
			std::cerr << e.what() << line << std::endl;

		} catch ( IN_EmptyValue& e ) {
			std::cerr << e.what() << line << std::endl;

		} catch ( IN_NotNumericValue& e ) {
			std::cerr << e.what() << line << std::endl;

		} catch ( IN_NotPositiveNumber& e ) {
			std::cerr << e.what() << line << std::endl;

		} catch ( IN_OutOfRange& e ) {
			std::cerr << e.what() << line << std::endl;

		} catch ( IN_NoSeparator& e ) {
			std::cerr << e.what() << line << std::endl;
		}
	}
}

void BitcoinExchange::loadDatabase() {
    
	std::ifstream fileStream(BITCOIN_DB);
    if (!fileStream.is_open())
		throw DB_NotOpen();

    std::string line;
	std::getline(fileStream, line);

    while (std::getline(fileStream, line)) {

		Line parsedLine = parseLine(line, DB);
		_rates[parsedLine.date.dateStr] = parsedLine.value;

    }
}