#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

#include "../Exceptions/PmergeMeExceptions.hpp"

#define THRESHOLD 10

class PmergeMe {
    public:
        PmergeMe(int ac, char **av);
        void	run(void);
        void	printData() const;

    private:
        std::vector<int>	_vecData;
        std::deque<int>		_deqData;
        std::vector<int>	_sortedVecData;
		std::deque<int>		_sortedDeqData;
        
        // Parsing
        void parseNumbers(int ac, char **av);
        
        // Print functions
        void printSortedData() const;
        
        // Insertion sort
        void insertionSortVec(std::vector<int>& vec, size_t left, size_t right);
        void insertionSortDeq(std::deque<int>& deq, size_t left, size_t right);
        
        // Ford-Johnson for vector
        void fordJohnsonAux(std::vector<int>& data);
        void fordJohnsonVec(std::vector<int>& vec, size_t left, size_t right);
        
        // Ford-Johnson for deque
        void fordJohnsonAuxDeq(std::deque<int>& data);
        void fordJohnsonDeq(std::deque<int>& deq, size_t left, size_t right);
        
        // Jacobsthal utilities
        std::vector<int> generateJacobsthal(int maxValue);
        std::vector<int> createInsertionOrder(const std::vector<int>& jacobsthal, int numLosers);
};

#include "PmergeMe.tpp"

#endif