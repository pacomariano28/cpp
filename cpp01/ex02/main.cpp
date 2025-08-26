#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPtr = &str;
	std::string& stringRef = str;

	// Imprimir los valores
    std::cout << "Value of string variable: " << str << std::endl;
    std::cout << "Value of the ptr of str stored in stringPTR: " << stringPtr << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringRef << std::endl;

    return 0;
}