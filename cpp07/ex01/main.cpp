#include "Iter.hpp"
#include <iostream>

void	printInt(int const& x) {
	std::cout << x << std::endl;
}

void	incrementInt(int& x) {
	x += 1;
}

void	printString(std::string const& x) {
	std::cout << x << std::endl;
}

void	incrementString(std::string& x) {
	x += "!";
}

void	printElements(int* arr, const size_t len) {
	for(size_t i = 0; i < len; ++i) {
		std::cout << arr[i] << std::endl;
	}
}

int main() {
	int arr[] = {2,5,6,1};
	const std::string arr2[] = {"hola", "antonimodevlachupa", "es broma <3"};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t len2 = sizeof(arr2) / sizeof(arr2[0]);

	iter(arr, len, printInt);
	std::cout << std::endl;
	iter(arr, len, incrementInt);
	std::cout << std::endl;
	iter(arr, len, printInt);

	std::cout << std::endl;
	iter(arr2, len2, printString);
	std::cout << std::endl;
	iter(arr2, len2, incrementString);
	std::cout << std::endl;
	iter(arr2, len2, printString);
}