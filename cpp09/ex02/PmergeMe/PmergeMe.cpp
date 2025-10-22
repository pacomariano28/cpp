#include "PmergeMe.hpp"
#include "../Exceptions/PmergeMeExceptions.hpp"
#include <sstream>
#include <climits>

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