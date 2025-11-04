#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <cstddef>
#include "../Exceptions/Exceptions.hpp"

// CONSTANTS
static const int CURRENT_YEAR = getCurrentYear();
static const size_t DATE_LENGTH = 10;
static const size_t YEAR_LENGTH = 4;
static const size_t MONTH_LENGTH = 2;
static const size_t DAY_LENGTH = 2;
static const size_t YEAR_POS = 0;
static const size_t MONTH_POS = 5;
static const size_t DAY_POS = 8;
static const float 	MAX_VALUE = 1000.0f;
static const int 	MIN_MONTH = 1;
static const int 	MAX_MONTH = 12;
static const int 	MIN_DAY = 1;
static const int 	MAX_DAY = 31;


BitcoinExchange::BitcoinExchange(const std::string& inputFile) {
    try {

        loadDatabase();
        processInputFile(inputFile);

    } catch(const DB_NotOpen& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);

    } catch(const IN_NotOpen& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);

    } catch(const DB_NoSeparatorFound& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);

    } catch(const DB_BadInput& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);

    } catch(const DB_NotPositiveNumber& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);

    }
}

BitcoinExchange::~BitcoinExchange(void) {}

// PRIVATE HELPER METHODS ------------------------------------------------------------------------------------

static int getCurrentYear() {
    time_t rawTime;
    struct tm* timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    return timeInfo->tm_year + 1900;
}

bool BitcoinExchange::isFutureDate(const std::string& date) const {
    time_t rawTime;
    struct tm* timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    
    int currentYear = timeInfo->tm_year + 1900;
    int currentMonth = timeInfo->tm_mon + 1;
    int currentDay = timeInfo->tm_mday;
    
    std::string yearStr = date.substr(YEAR_POS, YEAR_LENGTH);
    std::string monthStr = date.substr(MONTH_POS, MONTH_LENGTH);
    std::string dayStr = date.substr(DAY_POS, DAY_LENGTH);
    
    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());
    
    if (year > currentYear)
        return true;
    if (year < currentYear)
        return false;
    if (month > currentMonth)
        return true;
    if (month < currentMonth)
        return false;
    if (day > currentDay)
        return true;
    
    return false;
}


bool BitcoinExchange::isNumericString(const std::string& str, size_t expectedLength) const {
    if (str.length() != expectedLength)
        return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidDateRange(const Date& date) const {
     return (date.month >= MIN_MONTH && date.month <= MAX_MONTH && 
            date.day >= MIN_DAY && date.day <= MAX_DAY && date.year <= CURRENT_YEAR);
}

float BitcoinExchange::parseFloat(const std::string& str, bool& success) const {
    char* end;
    float result = std::strtof(str.c_str(), &end);
    success = (*end == '\0' && end != str.c_str());
    return result;
}

bool BitcoinExchange::isValidInputValue(float value) const {
    if (value < 0) {
        std::cout << ERROR_NOT_POSITIVE << std::endl;
        return false;
    }
    if (value > MAX_VALUE) {
        std::cout << ERROR_TOO_LARGE << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::skipHeader(std::ifstream& fileStream) const {
    std::string line;
    std::getline(fileStream, line);
}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const {
    if (date.length() != DATE_LENGTH || date[4] != '-' || date[7] != '-')
        return false;
	return true;
}

Date BitcoinExchange::getDate(const std::string& line) {
	Date result;

	// comprobaciones
	if (!isValidDateFormat(line)) {
		result.err_msg = ERROR_BAD_INPUT;
		return result;
	}
	
	result.year = std::atoi(line.substr(YEAR_POS, YEAR_LENGTH).c_str());
    result.month = std::atoi(line.substr(MONTH_POS, MONTH_LENGTH).c_str());
    result.day = std::atoi(line.substr(DAY_POS, DAY_LENGTH).c_str());

	return result;
}

ParsedLine BitcoinExchange::parseLine(const std::string& line, char separator) const {
    ParsedLine result;
    size_t pos = line.find(separator);
    
    if (pos == std::string::npos) {
        result.err_msg = ERROR_BAD_FORMAT;
        return result;
    }

	result.date = getDate(line.substr(0, pos));

    bool parseSuccess;
    result.value = parseFloat(line.substr(pos + 1), parseSuccess);
    result.isValid = parseSuccess;
    
    return result;
}

void BitcoinExchange::displayResult(const std::string& date, float value, float rate) const {
    float result = value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::displayError(std::string& err_msg, const std::string& context) const {
    std::cout << err_msg << context << std::endl;
}

// PUBLIC METHODS ------------------------------------------------------------------------------------

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream fileStream(filename.c_str());

	if (!fileStream.is_open()) throw IN_NotOpen();

    skipHeader(fileStream);

    std::string line;
    while (std::getline(fileStream, line)) {
        processInputLine(line);
    }
}

static void cleanLine(std::string& line) {
    std::istringstream iss(line);
    std::string result;
    std::string word;
    
    while (iss >> word) {
        result += word;
    }
    
    line = result;
}

void BitcoinExchange::processInputLine(std::string& line) {
    
	cleanLine(line);
	ParsedLine parsed = parseLine(line, '|');
    
    if (!parsed.err_msg.empty()) {
        displayError(parsed.err_msg, line);
        return;
    }
    
    if (!isValidDateFormat(parsed.date)) {
        displayError(ERROR_BAD_INPUT, parsed.date);
        return;
    }
    
    if (!isValidInputValue(parsed.value)) {
        return;
    }
    
    float rate = findRate(parsed.date);
    displayResult(parsed.date, parsed.value, rate);
}

float BitcoinExchange::findRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _rates.upper_bound(date);
    if (it == _rates.begin()) {
        return _rates.begin()->second;
    }
    --it;
    return it->second;
}

void BitcoinExchange::loadDatabase() {
    std::ifstream fileStream(BITCOIN_DB);

    if (!fileStream.is_open()) throw DB_NotOpen();
    
    skipHeader(fileStream);
    
    std::string line;
    while (std::getline(fileStream, line))
        loadDatabaseLine(line);
}

void BitcoinExchange::loadDatabaseLine(const std::string& line) {

	ParsedLine parsed = parseLine(line, ',');

    if (!parsed.isValid) 						
		throw DB_NoSeparatorFound(line);
    
    if (!isValidDateFormat(parsed.date))
		throw DB_BadInput(line);
    
    if (parsed.value < 0)
		throw DB_NotPositiveNumber(line);

    _rates[parsed.date] = parsed.value;
}