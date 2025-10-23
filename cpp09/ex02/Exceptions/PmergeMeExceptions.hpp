#pragma once

#include <exception>

#define DIFF_PARAMS 	"Error: diff params. Usage ./PmergeMe <int1> <int2> ..."
#define NEGATIVE_NUMBER "Error: negative number found."
#define OUT_OF_RANGE	"Error: number out of range."
#define INVALID_NUMBER	"Error: invalid number."




class PmergeMeException : public std::exception {
	public:
		virtual const char* what() const throw() = 0; // pura virtual
};

class DiffParams : public PmergeMeException {
	public:
		const char* what() const throw() {
			return DIFF_PARAMS;
		}
};

class NegativeNumber : public PmergeMeException {
	public:
		const char* what() const throw() {
			return NEGATIVE_NUMBER;
		}
};

class OutOfRange : public PmergeMeException {
	public:
		const char* what() const throw() {
			return OUT_OF_RANGE;
		}
};

class InvalidNumber : public PmergeMeException {
	public:
		const char* what() const throw() {
			return INVALID_NUMBER;
		}
};