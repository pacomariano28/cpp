#include "Span.hpp"

template<typename InputIterator>
void			Span::addNumbers(InputIterator begin, InputIterator end) {
	for (InputIterator it = begin; it != end; ++it) {
		addNumber(*it);
	}
}