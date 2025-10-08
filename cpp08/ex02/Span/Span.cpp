#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

// COF ------------------------------------------------------------------------

Span::Span(void) : _v() ,_size(0) {}

Span::Span(const unsigned int size)  : _v(), _size(size){}

Span::Span(const Span& other) : _v(other._v), _size(other._size) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_v = other._v;
		_size = other._size;
	}
	return *this;
}

Span::~Span(void) {}

// METHODS --------------------------------------------------------------------

void			Span::addNumber(const int number) {
	if (_v.size() >= _size)
		throw std::runtime_error("Span is full!");
	_v.push_back(number);
}

unsigned int	Span::shortestSpan(void) const {
	if (_v.size() < 2)
		throw std::runtime_error("Not enough elements in the container!");
	
	std::vector<int> tmp(_v);
	std::sort(tmp.begin(), tmp.end());

	unsigned int finalRes = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for(size_t i = 0; i < tmp.size() - 1; ++i) {
		unsigned int currentRes = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);

		if (finalRes > currentRes)
			finalRes = currentRes;
	}
	return finalRes;
}

unsigned int	Span::longestSpan(void) const {
	if (_size < 2)
		throw std::runtime_error("Not enough elements in the container!");

	unsigned int min = *std::min_element(_v.begin(), _v.end());
	unsigned int max = *std::max_element(_v.begin(), _v.end());

	return static_cast<unsigned int>(max - min);
}

// ----------------------------------------------------------------------------