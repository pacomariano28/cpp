#include "ScalarConverter.hpp"
#include <iostream>  // para std::cout, std::endl
#include <climits>   // para CHAR_MIN, CHAR_MAX, INT_MIN, INT_MAX
#include <string>    // para std::string
#include <cmath>     // para std::isnan(), std::isinf()
#include <cstdlib>   // para std::atoi(), std::atof()
#include <cfloat> 	 // para límites de float (si son necesarios)
#include <iomanip>   // para std::fixed, std::setprecision (controlar decimales)

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
		std::cout << "impossible" << std::endl;
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printChar(const double value) {
	std::cout << "Char: ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else {
		char c = static_cast<char>(value);
		
		if (c >= 32 && c <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void ScalarConverter::printFloat(const double value) {
    std::cout << "Float: ";
    
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else if (value < -FLT_MAX || value > FLT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        float f = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(const double value) {
    std::cout << "Double: ";
    
    if (std::isnan(value)) {
        std::cout << "nan";
    } else if (std::isinf(value)) {
        std::cout << (value > 0 ? "+inf" : "-inf");
    } else {
        std::cout << std::fixed << std::setprecision(1) << value;
    }
    std::cout << std::endl;
}

void	ScalarConverter::printConversion(const double value) {
	printInt(value);
	printChar(value);
	printFloat(value);
	printDouble(value);
}

/* static bool insideLimits(const std::string& literal) {

	double value = std::atof(literal.c_str());
	if (value < INT_MIN || value > INT_MAX) {
		return false;
	}

	return true;
} */

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
				//value = (insideLimits(literal.c_str())) ? static_cast<double>(std::atoi(literal.c_str())) : throw std::runtime_error("Error: Int out of range");
				value = static_cast<double>(std::atof(literal.c_str()));
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

