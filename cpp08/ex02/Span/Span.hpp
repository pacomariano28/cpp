#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	private:
		std::vector<int> 	_v;
		unsigned int 		_size;

	public:
		Span(void);
		Span(const unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void			addNumber(const int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		template<typename InputIterator>
		void			addNumbers(InputIterator begin, InputIterator end);
};

#include "Span.tpp"

#endif