#include "MutantStack.hpp"

// COF ------------------------------------------------------------------------

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other) :  std::stack<T>(other) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {}

// METHODS ------------------------------------------------------------------------

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return this->c.end();
}