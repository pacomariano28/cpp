#pragma once

#include <exception>

#define DIVISOR_0           	"Error: cannot divide by 0."
#define OUT_OF_RANGE      		"Error: result out of int range."
#define NOT_ENOUGH_ARGUMENTS	"Error: diff params. Usage ./RPN 'values'"
#define NOT_ENOUGH_NUMBERS  	"Error: needed at least 2 numbers to operate."
#define MORE_ARGS_LEFT      	"Error: there is still more args to be processed."
#define INVALID_ARG         	"Error: invalid args. Only 9 positive numbers whose value is less than 10."

class RPNExceptions : public std::exception {
	public:
		virtual const char* what() const throw() = 0;
};

class LackOfArguments : public RPNExceptions {
	public:
		virtual const char* what() const throw() {
			return NOT_ENOUGH_ARGUMENTS;
		}
};

class LackOfNumbers : public RPNExceptions {
public:
    virtual const char* what() const throw() {
        return NOT_ENOUGH_NUMBERS;
    }
};

class InvalidArg : public RPNExceptions {
	public:
		virtual const char* what() const throw() {
			return INVALID_ARG;
		}
};

class DivisionByZero : public RPNExceptions {
public:
    virtual const char* what() const throw() {
        return DIVISOR_0;
    }
};

class ArgsLeft : public RPNExceptions {
public:
    virtual const char* what() const throw() {
        return MORE_ARGS_LEFT;
    }
};

class OutOfRange : public RPNExceptions {
public:
    virtual const char* what() const throw() {
        return OUT_OF_RANGE;
    }
};