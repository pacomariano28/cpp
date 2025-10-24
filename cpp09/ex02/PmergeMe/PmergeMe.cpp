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

}

void	PmergeMe::fordJohnsonAux(std::vector<int>& data) {
	size_t size = data.size();

	if (size <= 1)
		return;

	std::vector<int> winners, losers;
	bool hasOddElement = false;
	int oddElement = 0;

	// Procesar pares completos
    for (size_t i = 0; i + 1 < size; i += 2) {
        if (data[i] > data[i + 1]) {
            winners.push_back(data[i]);
            losers.push_back(data[i + 1]);
        } else {
            winners.push_back(data[i + 1]);
            losers.push_back(data[i]);
        }
    }

	if (size % 2 == 1) {
		hasOddElement = true;
		oddElement = data[size-1];
	}

	// recursion en ganadores
	if (!winners.empty())
		fordJohnsonAux(winners);

	// creamos la main chain con el primer perdedor seguido de los ganadores ordenados
	std::vector<int> mainChain;
	if (!losers.empty())
		mainChain.push_back(losers[0]);

	// copiamos el resto de winners
	for (size_t i = 0; i < winners.size(); ++i) {
		mainChain.push_back(winners[i]);
	}

	// HAY QUE SACAR LA SECUENCIA JACOBSTHAL QUE A SABER COMO SE HACE
	data = mainChain;
}


void 	PmergeMe::fordJohnsonVec(std::vector<int>& vec, size_t left, size_t right) {
	size_t size = right - left + 1;

	if (size <= THRESHOLD) {
		insertionSortVec(vec, left, right);
		return;
	}

	// TODO: Implementar los 5 pasos del Ford-Johnson
	std::vector<int> tempData;
	tempData.reserve(size);

	for (size_t i = left; i <= right; ++i) {
		tempData.push_back(vec[i]);
	}

	fordJohnsonAux(tempData);

	for (size_t i = 0; i < size; ++i) {
        vec[left + i] = tempData[i];
    }

    // Paso 1: Crear pares y encontrar ganadores/perdedores
    // Paso 2: Recursión en ganadores
    // Paso 3: Crear main chain
    // Paso 4: Insertar perdedores en orden especial
    // Paso 5: Manejar elemento suelto (si n es impar)
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