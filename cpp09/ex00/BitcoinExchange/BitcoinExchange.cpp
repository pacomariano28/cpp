#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

// CONSTANTS
static const size_t DATE_LENGTH = 10;
static const size_t YEAR_LENGTH = 4;
static const size_t MONTH_LENGTH = 2;
static const size_t DAY_LENGTH = 2;
static const size_t YEAR_POS = 0;
static const size_t MONTH_POS = 5;
static const size_t DAY_POS = 8;
static const float MAX_VALUE = 1000.0f;
static const int MIN_MONTH = 1;
static const int MAX_MONTH = 12;
static const int MIN_DAY = 1;
static const int MAX_DAY = 31;

static const char* ERROR_TOO_LARGE = "Error: too large a number.";
static const char* ERROR_NOT_POSITIVE = "Error: not a positive number.";
static const char* ERROR_BAD_INPUT = "Error: bad input => ";
static const char* ERROR_COULD_NOT_OPEN = "Error: could not open file.";
static const char* ERROR_DB_NOT_OPEN = "Error: not possible to open the file";
static const char* ERROR_BAD_FORMAT = "Error: bad format in database line: ";

BitcoinExchange::BitcoinExchange(const std::string& inputFile) {
    try {
        loadDatabase();
        processInputFile(inputFile);
    } catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

BitcoinExchange::~BitcoinExchange(void) {}

// PRIVATE HELPER METHODS ------------------------------------------------------------------------------------

bool BitcoinExchange::isValidDateFormat(const std::string& date) const {
    if (date.length() != DATE_LENGTH || date[4] != '-' || date[7] != '-')
        return false;

    return isValidDateComponents(date);
}

bool BitcoinExchange::isValidDateComponents(const std::string& date) const {
    std::string yearStr = date.substr(YEAR_POS, YEAR_LENGTH);
    std::string monthStr = date.substr(MONTH_POS, MONTH_LENGTH);
    std::string dayStr = date.substr(DAY_POS, DAY_LENGTH);

    if (!isNumericString(yearStr, YEAR_LENGTH) ||
        !isNumericString(monthStr, MONTH_LENGTH) ||
        !isNumericString(dayStr, DAY_LENGTH))
        return false;

    return isValidDateRange(monthStr, dayStr);
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

bool BitcoinExchange::isValidDateRange(const std::string& monthStr, const std::string& dayStr) const {
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    return (month >= MIN_MONTH && month <= MAX_MONTH && 
            day >= MIN_DAY && day <= MAX_DAY);
}

std::string BitcoinExchange::trimWhitespace(const std::string& str) const {
    if (str.empty())
        return str;

    size_t start = findFirstNonWhitespace(str);
    if (start == std::string::npos)
        return "";

    size_t end = findLastNonWhitespace(str);
    return str.substr(start, end - start + 1);
}

size_t BitcoinExchange::findFirstNonWhitespace(const std::string& str) const {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] != ' ' && str[i] != '\t')
            return i;
    }
    return std::string::npos;
}

size_t BitcoinExchange::findLastNonWhitespace(const std::string& str) const {
    for (size_t i = str.length(); i > 0; --i) {
        if (str[i-1] != ' ' && str[i-1] != '\t')
            return i-1;
    }
    return std::string::npos;
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

bool BitcoinExchange::isValidDatabaseValue(float value) const {
    return value >= 0;
}

void BitcoinExchange::validateFileOpen(const std::ifstream& fileStream, const char* errorMsg) const {
    if (!fileStream.is_open())
        throw std::runtime_error(errorMsg);
}

void BitcoinExchange::skipHeader(std::ifstream& fileStream) const {
    std::string line;
    std::getline(fileStream, line);
}

ParsedLine BitcoinExchange::parseLine(const std::string& line, char separator) const {
    ParsedLine result;
    size_t pos = line.find(separator);
    
    if (pos == std::string::npos) {
        result.isValid = false;
        return result;
    }
    
    result.date = trimWhitespace(line.substr(0, pos));

    bool parseSuccess;
    result.value = parseFloat(trimWhitespace(line.substr(pos + 1)), parseSuccess);
    result.isValid = parseSuccess;
    
    return result;
}

void BitcoinExchange::displayResult(const std::string& date, float value, float rate) const {
    float result = value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::displayError(const char* errorMsg, const std::string& context) const {
    std::cout << errorMsg << context << std::endl;
}

// PUBLIC METHODS ------------------------------------------------------------------------------------

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream fileStream(filename.c_str());
    validateFileOpen(fileStream, ERROR_COULD_NOT_OPEN);
    
    skipHeader(fileStream);
    
    std::string line;
    while (std::getline(fileStream, line)) {
        processInputLine(line);
    }
}

void BitcoinExchange::processInputLine(const std::string& line) {
    ParsedLine parsed = parseLine(line, '|');
    
    if (!parsed.isValid) {
        displayError(ERROR_BAD_INPUT, line);
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
    validateFileOpen(fileStream, ERROR_DB_NOT_OPEN);
    
    skipHeader(fileStream);
    
    std::string line;
    while (std::getline(fileStream, line)) {
        loadDatabaseLine(line);
    }
}

void BitcoinExchange::loadDatabaseLine(const std::string& line) {
    ParsedLine parsed = parseLine(line, ',');
    
    if (!parsed.isValid)
        throw std::runtime_error(std::string(ERROR_BAD_FORMAT) + line);
    
    if (!isValidDateFormat(parsed.date))
        throw std::runtime_error(std::string(ERROR_BAD_INPUT) + line);
    
    if (!isValidDatabaseValue(parsed.value))
        throw std::runtime_error(ERROR_NOT_POSITIVE);
    
    _rates[parsed.date] = parsed.value;
}