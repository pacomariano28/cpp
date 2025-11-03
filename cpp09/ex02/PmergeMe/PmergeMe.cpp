#include "PmergeMe.hpp"
#include "../Exceptions/PmergeMeExceptions.hpp"
#include <sstream>
#include <climits>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstddef>

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

void PmergeMe::printSortedData() const{
    std::vector<int>::const_iterator it;
    for (it = _sortedVecData.begin(); it != _sortedVecData.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void	PmergeMe::insertionSortVec(std::vector<int>& vec, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = vec[i];
        size_t j = i;
        
        while (j > left && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

void	PmergeMe::insertionSortDeq(std::deque<int>& deq, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = deq[i];
        size_t j = i;
        
        while (j > left && deq[j - 1] > key) {
            deq[j] = deq[j - 1];
            --j;
        }
        deq[j] = key;
    }
}

std::vector<int> PmergeMe::generateJacobsthal(int maxValue) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);  // J(0) = 0
    jacobsthal.push_back(1);  // J(1) = 1
    
    while (jacobsthal.back() < maxValue) {
        int next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::vector<int> PmergeMe::createInsertionOrder(const std::vector<int>& jacobsthal, int numLosers) {
    std::vector<int> order;
    std::vector<bool> inserted(numLosers + 1, false);  // Trackear qué índices ya insertamos

    // Insertar según Jacobsthal
    for (size_t k = 2; k < jacobsthal.size(); ++k) {
        int start = jacobsthal[k-1];
        int end = jacobsthal[k];
        
        // Insertar en orden inverso desde end hasta start+1
        for (int i = std::min(end, numLosers); i > start; --i) {
            order.push_back(i);
            inserted[i] = true;  // Marcar como insertado
        }
    }
    
    // Insertar los índices que NO fueron insertados (desde 1 hasta numLosers)
    for (int i = 1; i <= numLosers; ++i) {
        if (!inserted[i]) {
            order.push_back(i);
        }
    }

    return order;
}

void	PmergeMe::fordJohnsonAux(std::vector<int>& data) {
    size_t size = data.size();

    if (size <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasOddElement = false;
    int oddElement = 0;

    // Procesar pares completos
    for (size_t i = 0; i + 1 < size; i += 2) {
        int first = data[i];
        int second = data[i + 1];

        // Crear par donde first = winner (mayor), second = loser (menor)
        if (first > second) {
            pairs.push_back(std::make_pair(first, second));
        } else {
            pairs.push_back(std::make_pair(second, first));
        }
    }

    if (size % 2 == 1) {
        hasOddElement = true;
        oddElement = data[size-1];
    }

    // Extraer winners para recursión
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    // Recursión en ganadores
    if (!winners.empty())
        fordJohnsonAux(winners);

    // Reordenar pairs según winners ordenados
    std::vector<std::pair<int, int> > orderedWinners;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < winners.size(); ++i) {
        int currentWinner = winners[i];

        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == currentWinner) {
                orderedWinners.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // Crear main chain
    std::vector<int> mainChain;
    if (!orderedWinners.empty()) {
        mainChain.push_back(orderedWinners[0].second);  // Primer loser
    }

    for (size_t i = 0; i < orderedWinners.size(); ++i) {
        mainChain.push_back(orderedWinners[i].first);   // Winners ordenados
    }

    // Insertar losers restantes usando orden Jacobsthal
    if (orderedWinners.size() > 1) {
        int numLosersToInsert = orderedWinners.size() - 1;
        std::vector<int> jacobsthal = generateJacobsthal(numLosersToInsert);
        std::vector<int> insertionOrder = createInsertionOrder(jacobsthal, numLosersToInsert);
        
        for (size_t i = 0; i < insertionOrder.size(); ++i) {
            int loserIndex = insertionOrder[i];
            int loserValue = orderedWinners[loserIndex].second;
            int winnerValue = orderedWinners[loserIndex].first;

            // Encontrar posición límite del winner en mainChain
            std::vector<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winnerValue);

            // Buscar posición de inserción usando búsqueda binaria
            std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), winnerPos + 1, loserValue);

            // Insertar el loser
            mainChain.insert(insertPos, loserValue);
        }
    }

    // Manejar elemento impar
    if (hasOddElement) {
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(insertPos, oddElement);
    }

    data = mainChain;
}

void	PmergeMe::fordJohnsonAuxDeq(std::deque<int>& data) {
    size_t size = data.size();

    if (size <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool hasOddElement = false;
    int oddElement = 0;

    // Procesar pares completos
    for (size_t i = 0; i + 1 < size; i += 2) {
        int first = data[i];
        int second = data[i + 1];
        
        if (first > second) {
            pairs.push_back(std::make_pair(first, second));
        } else {
            pairs.push_back(std::make_pair(second, first));
        }
    }

    if (size % 2 == 1) {
        hasOddElement = true;
        oddElement = data[size-1];
    }

    // Extraer winners para recursión
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    // Recursión en ganadores
    if (!winners.empty())
        fordJohnsonAuxDeq(winners);

    // Reordenar pairs según winners ordenados
    std::vector<std::pair<int, int> > orderedWinners;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < winners.size(); ++i) {
        int currentWinner = winners[i];
        
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].first == currentWinner) {
                orderedWinners.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // Crear main chain
    std::deque<int> mainChain;
    if (!orderedWinners.empty()) {
        mainChain.push_back(orderedWinners[0].second);
    }

    for (size_t i = 0; i < orderedWinners.size(); ++i) {
        mainChain.push_back(orderedWinners[i].first);
    }

    // Insertar losers restantes usando orden Jacobsthal
    if (orderedWinners.size() > 1) {
        int numLosersToInsert = orderedWinners.size() - 1;
        std::vector<int> jacobsthal = generateJacobsthal(numLosersToInsert);
        std::vector<int> insertionOrder = createInsertionOrder(jacobsthal, numLosersToInsert);
        
        for (size_t i = 0; i < insertionOrder.size(); ++i) {
            int loserIndex = insertionOrder[i];
            int loserValue = orderedWinners[loserIndex].second;
            int winnerValue = orderedWinners[loserIndex].first;
            
            std::deque<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winnerValue);
            std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), winnerPos + 1, loserValue);
            mainChain.insert(insertPos, loserValue);
        }
    }

    // Manejar elemento impar
    if (hasOddElement) {
        std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(insertPos, oddElement);
    }

    data = mainChain;
}

void 	PmergeMe::fordJohnsonVec(std::vector<int>& vec, size_t left, size_t right) {
    size_t size = right - left + 1;

    if (size <= THRESHOLD) {
        insertionSortVec(vec, left, right);
        return;
    }

    std::vector<int> tempData;
    tempData.reserve(size);

    for (size_t i = left; i <= right; ++i) {
        tempData.push_back(vec[i]);
    }

    fordJohnsonAux(tempData);

    for (size_t i = 0; i < size; ++i) {
        vec[left + i] = tempData[i];
    }
}

void 	PmergeMe::fordJohnsonDeq(std::deque<int>& deq, size_t left, size_t right) {
    size_t size = right - left + 1;

    if (size <= THRESHOLD) {
        insertionSortDeq(deq, left, right);
        return;
    }

    std::deque<int> tempData;

    for (size_t i = left; i <= right; ++i) {
        tempData.push_back(deq[i]);
    }

    fordJohnsonAuxDeq(tempData);

    for (size_t i = 0; i < size; ++i) {
        deq[left + i] = tempData[i];
    }
}

void PmergeMe::run() {
    // 1. Mostrar "Before:"
    std::cout << "Before: ";
    //printData();
    
    // 2. Copiar datos para sorting
    _sortedVecData = _vecData;
    _sortedDeqData = _deqData;
    
    // 3. Ordenar vector y medir tiempo
    clock_t startVec = clock();
    fordJohnsonVec(_sortedVecData, 0, _sortedVecData.size() - 1);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) * CLOCKS_PER_SEC / 100000000000;
    
    // 4. Ordenar deque y medir tiempo
    clock_t startDeq = clock();
    fordJohnsonDeq(_sortedDeqData, 0, _sortedDeqData.size() - 1);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) * CLOCKS_PER_SEC / 100000000000;

	std::cout << std::endl;
    
    // 5. Mostrar "After:"
    std::cout << "After: ";
    printSortedData();
    
    // 6. Mostrar tiempos
	std::cout << timeDeq << std::endl;
    /* std::cout << "Time to process a range of " << _vecData.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deqData.size() 
              << " elements with std::deque : " << timeDeq << " us" << std::endl; */
}