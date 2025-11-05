#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <cstddef>
#include <climits> 
#include <cfloat>
#include "../Exceptions/Exceptions.hpp"

// CONSTANTS
//static const int 	CURRENT_YEAR = getCurrentYear();
static const float 	MAX_VALUE = 1000.0f;
static const int 	MIN_MONTH = 1;
static const int 	MAX_MONTH = 12;
static const int 	MIN_DAY = 1;
static const int 	MAX_DAY = 31;

static const size_t YEAR_LENGTH = 4;
static const size_t YEAR_POS = 0;
static const size_t DATE_LENGTH = 10;
static const size_t MONTH_LENGTH = 2;
static const size_t MONTH_POS = 5;
static const size_t DAY_LENGTH = 2;
static const size_t DAY_POS = 8;



BitcoinExchange::BitcoinExchange(const std::string& inputFile) {
	loadDatabase();
}

BitcoinExchange::~BitcoinExchange(void) {}

// METHODS ------------------------------------------------------------------------------------

static bool isDateInRange(Date& date) {
	if (date.year < 2009 || date.year > 2025)
		return false;
	if (date.month < 1 || date.month > 12)
		return false;
	if (date.day < 1)
		return false;

	int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (date.month == 2 && ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0))
		days_in_month[1] = 29;
	if (date.day > days_in_month[date.month - 1])
		return false;

	return true;
}

static Date getDate(const std::string& dateStr, Type type) {
    if (dateStr.length() != DATE_LENGTH || dateStr[4] != '-' || dateStr[7] != '-') {
		if (type == DB)
			throw DB_BadInput(dateStr);

		if (type == INPUT)
			throw IN_BadInput(dateStr);
	}

	Date date;

    date.day 	= std::atoi(dateStr.substr(DAY_POS, DAY_LENGTH).c_str());
    date.month 	= std::atoi(dateStr.substr(MONTH_POS, MONTH_LENGTH).c_str());
	date.year 	= std::atoi(dateStr.substr(YEAR_POS, YEAR_LENGTH).c_str());
	date.dateStr = dateStr;

	if (!isDateInRange(date)){
		if (type == DB)
			throw DB_BadInput(dateStr);

		if (type == INPUT)
			throw IN_BadInput(dateStr);
	}

	return date;

}

static float getValue(const std::string& valueStr, Type type) {
    if (valueStr.empty()) {
        if (type == DB)
            throw DB_BadInput(valueStr);
        if (type == INPUT)
            throw IN_BadInput(valueStr);
    }
    
    if (valueStr.length() > 15) {
        if (type == DB)
            throw DB_BadInput(valueStr);
        if (type == INPUT)
            throw IN_BadInput(valueStr);
    }
    
    // Convertir a double primero para detectar overflow
    double tempValue = std::atof(valueStr.c_str());
    
    // Verificar overflow/underflow para float
    if (tempValue > static_cast<double>(FLT_MAX)) {
        if (type == DB)
            throw DB_BadInput(valueStr);
        if (type == INPUT)
            throw IN_BadInput(valueStr);
    }
    
    if (tempValue < -static_cast<double>(FLT_MAX)) {
        if (type == DB)
            throw DB_BadInput(valueStr);
        if (type == INPUT)
            throw IN_BadInput(valueStr);
    }
    
    float value = static_cast<float>(tempValue);
    
    if (type == INPUT) {
        if (value < 0) {
            throw IN_BadInput("Value cannot be negative");
        }
        if (value > MAX_VALUE) {
            throw IN_BadInput(valueStr);
        }
    }
    
    return value;
}

static Line parseLine(const std::string& line, Type type) {
	
	
	std::istringstream 	iss(line);

	std::string			cleanLine;
	std::string			word;

	while  (iss >> word)
		cleanLine += word;

	size_t separator = cleanLine.find((type == DB) ? ',' : '|');

	if (separator == std::string::npos) {
		if (type == DB)
			throw DB_BadInput(cleanLine);

		if (type == INPUT)
			throw IN_BadInput(cleanLine);
	}

	Line parsedLine;
	parsedLine.date = getDate(cleanLine.substr(0, separator), type);
	parsedLine.value = getValue(cleanLine.substr(separator + 1), type);
	parsedLine.type = type;

	return parsedLine;
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

