#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <cfloat>
#include <cstdlib>

// COF ---------------------------------------------------------------------------

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { 
	(void)other; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    (void)other; 
    return *this; 
}

ScalarConverter::~ScalarConverter(void) {}

// PRIVATE METHODS ---------------------------------------------------------------------------

TypeIdentifier	ScalarConverter::detectType(const std::string& literal) {
	if (literal.empty())
		throw EmptyInput();

	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return CHAR_TYPE;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return FLOAT_TYPE;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return DOUBLE_TYPE;

	if (literal[literal.length() - 1] == 'f')
		return FLOAT_TYPE;
	
	if (literal.find('.') != std::string::npos)
		return DOUBLE_TYPE;
	
	return INT_TYPE;
}

void	ScalarConverter::printInt(const double value) {
	std::cout << "Int: ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printChar(const double value) {
	std::cout << "Char: ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible";
	else if (value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "impossible";
	
	char c = static_cast<char>(value);
	if (c >= 32 && c <= 126)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::printConversion(const double value) {
	printInt(value);
	printChar(value);
	printFloat(value);
	printDouble(value);
}

// PUBLIC METHODS ---------------------------------------------------------------------------

void	ScalarConverter::convert(const std::string& literal){
	try {
		TypeIdentifier literalType;
		double value;

		literalType = detectType(literal);

		switch(literalType) {
			case CHAR_TYPE:
				value = static_cast<double>(literal[1]);
				break;
			case INT_TYPE:
				value = static_cast<double>(std::atoi(literal.c_str()));
				break;
			case DOUBLE_TYPE:
				value = static_cast<double>(std::atof(literal.c_str()));
				break;
			case FLOAT_TYPE:
				value = static_cast<double>(std::atof(literal.c_str()));
				break;
		}

		printConversion(value);

	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

