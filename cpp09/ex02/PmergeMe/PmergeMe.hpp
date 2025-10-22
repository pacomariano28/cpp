#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	public:
		PmergeMe(int ac, char **av);

	private:
		std::vector<int>	_vecData;
		std::deque<int>		_deqData;

	void	parseNumbers(int ac, char **av);
};

#endif