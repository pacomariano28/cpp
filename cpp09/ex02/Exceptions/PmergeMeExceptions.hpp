#pragma once

#include <exception>

class PmergeMeException : public std::exception {
	public:
		virtual const char* what() const throw() = 0; // pura virtual
};

class DiffParams : public PmergeMeException {
	public:
		const char* what() const throw() {
			return "Error: diff params. Usage ./PmergeMe <int1> <int2> ...";
		}
};

class NegativeNumber : public PmergeMeException {
	public:
		const char* what() const throw() {
			return "Error: negative number found.";
		}
};

class OutOfRange : public PmergeMeException {
	public:
		const char* what() const throw() {
			return "Error: number out of range.";
		}
};

class InvalidNumber : public PmergeMeException {
	public:
		const char* what() const throw() {
			return "Error: invalid number.";
		}
};