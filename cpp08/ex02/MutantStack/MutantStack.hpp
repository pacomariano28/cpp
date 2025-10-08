#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "../Span/Span.hpp"
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public: 
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(void);
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack(void);

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif
