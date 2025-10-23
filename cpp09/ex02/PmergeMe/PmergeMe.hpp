#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

#include "../Exceptions/PmergeMeExceptions.hpp"

class PmergeMe {
	public:
		PmergeMe(int ac, char **av);
		void	run(void);

	private:
		std::vector<int>	_vecData;
		std::deque<int>		_deqData;

	void	parseNumbers(int ac, char **av);
	void	printData(void) const;

	void	fordJohnsonVec(std::vector<int>& vec, size_t left, size_t right);
	void	fordJohnsonDeq(std::deque<int>& deq, size_t left, size_t right);
	void	insertionSortVec(std::vector<int>& vec, size_t left, size_t right);
/* 	template<typename Container>
	void	PmergeMe::fordJohnson(Container& arr); */
};

#include "PmergeMe.tpp"



#endif