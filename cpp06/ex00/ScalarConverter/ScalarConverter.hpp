#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <exception>

enum TypeIdentifier {
    CHAR_TYPE, 
    INT_TYPE, 
    FLOAT_TYPE, 
    DOUBLE_TYPE
};

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);

		static TypeIdentifier	detectType(const std::string& literal);
		static void				printConversion(const double value);

		static void 			printChar(double value);
		static void 			printInt(double value);
		static void 			printFloat(double value); 
		static void 			printDouble(double value);

	public:
		static void				convert(const std::string& literal);

		class EmptyInput : std::exception {
			public:
				virtual const char* what() const throw() {
					return "Empty input.";
				}
		};
};

#endif