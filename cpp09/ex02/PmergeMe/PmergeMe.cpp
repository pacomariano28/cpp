#include "PmergeMe.hpp"
#include "../Exceptions/PmergeMeExceptions.hpp"
#include <sstream>
#include <climits>
#include <iostream>

void	PmergeMe::parseNumbers(int ac, char **av) {
	for (int i = 1; i < ac; ++i) {
		std::istringstream iss(av[i]);
		long number;

		if (!(iss >> number))
			throw InvalidNumber();

		std::string remaining;
		if (iss >> remaining)
			throw InvalidNumber();

		if (number < 0)
			throw NegativeNumber();

		if (number > INT_MAX || number < INT_MIN)
			throw OutOfRange();

		_vecData.push_back(static_cast<int>(number));
		_deqData.push_back(static_cast<int>(number));
	}

	if (_vecData.empty())
		throw DiffParams();
}

PmergeMe::PmergeMe(int ac, char** av) {
	if (ac < 2)
		throw DiffParams();

	parseNumbers(ac, av);
}

void PmergeMe::printData() const{
	std::vector<int>::const_iterator it;
	for (it = _vecData.begin(); it != _vecData.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void	PmergeMe::insertionSortVec(std::vector<int>& vec, size_t left, size_t right) {
	// esta wea tiene que hacer las comparaciones de:

	/*
	
		[9,2,3,5] -> key: 1 value: 2

		(actual < anterior) ? [9,9,3,5] -> sustituimos la key actual con el valor anterior

		- ahora le decimos, 
	
	*/
}


void 	PmergeMe::fordJohnsonVec(std::vector<int>& vec, size_t left, size_t right) {
	const size_t THREESHOLD = 10;
	size_t elements = right - left + 1;
	
	if (elements <= THREESHOLD) {
		insertionSortVec(vec, left, right);  // Llama al que SÍ tiene bucle
		return;
	}

	// Divide
	size_t mid = left + (right - left) / 2;

	// Recursión (NO bucle)
	fordJohnsonVec(vec, left, mid);
	fordJohnsonVec(vec, mid + 1, right);

	// Merge
	mergeVec(vec, left, mid, right);
}


void PmergeMe::run() {
    // 1. Mostrar "Before: 3 5 9 7 4"
	std::cout << "Before: ";
	printData();
    
    // 2. Ordenar vector y medir tiempo

    
    // 3. Ordenar deque y medir tiempo
    
    // 4. Mostrar "After: 3 4 5 7 9"
	std::cout << "After: ";
	printData();
    
    // 5. Mostrar tiempos
}