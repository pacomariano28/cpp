#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <climits>

#include "Exceptions.hpp"

enum eTokenType {
    NUMBER,
    OPERATOR,
    INVALID
};

static eTokenType tokenType(const std::string& token) {
    
	if (token.length() == 1 && std::isdigit(token[0]))
		return NUMBER;

    if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/"))
        return OPERATOR;

    return INVALID;

}

static int inRange(int a, int b, char op) {
    
	switch (op) {
        case '+':
            if (b > 0 && a > INT_MAX - b) throw OutOfRange();
            if (b < 0 && a < INT_MIN - b) throw OutOfRange();
            return a + b;

        case '-':
            if (b < 0 && a > INT_MAX + b) throw OutOfRange();
            if (b > 0 && a < INT_MIN + b) throw OutOfRange();
            return a - b;

        case '*':
            if (a != 0 && (b > INT_MAX / a || b < INT_MIN / a)) throw OutOfRange();
            return a * b;

        case '/':
            if (a == INT_MIN && b == -1) throw OutOfRange();
            return a / b;

        default: throw InvalidArg();
    }

}

void processOperation(std::string& token, std::stack<int>& rpnStack) {
    
	if (rpnStack.size() < 2) 
		throw LackOfNumbers();

    int b = rpnStack.top();
	rpnStack.pop();
	
    int a = rpnStack.top();
	rpnStack.pop();

    switch(token[0]) {
        case '+': rpnStack.push(inRange(a, b, '+')); break;
        case '-': rpnStack.push(inRange(a, b, '-')); break;
        case '*': rpnStack.push(inRange(a, b, '*')); break;
        case '/':
            if (b == 0) throw DivisionByZero();
            rpnStack.push(inRange(a, b, '/'));
            break;
    }
}


void calc(int ac, char** av) {

	if (ac != 2)
		throw LackOfArguments();

    std::stack<int> 	rpnStack;
    std::string 		strInput(av[1]);
    std::istringstream 	iss(strInput);
    std::string 		token;

    while (iss >> token) {

        switch(tokenType(token)) {
            case NUMBER: 	rpnStack.push(std::atoi(token.c_str())); 	break;
            case OPERATOR: 	processOperation(token, rpnStack); 			break;
            case INVALID:   throw InvalidArg();
        }

    }

	if (token.empty())
		throw LackOfArguments();
	
    if (rpnStack.size() != 1)
        throw ArgsLeft();

    std::cout << rpnStack.top() << std::endl;
}


int main(int ac, char** av) {

	try  {	
		calc(ac, av);
	}
	catch ( LackOfArguments &e ) {
		std::cerr << e.what() << std::endl; 
	}
	catch ( ArgsLeft &e ) {
		std::cerr << e.what() << std::endl; 
	}
	catch ( InvalidArg &e ) {
		std::cerr << e.what() << std::endl; 
	}
	catch ( LackOfNumbers &e ) {
		std::cerr << e.what() << std::endl; 
	}
	catch ( DivisionByZero &e ) {
		std::cerr << e.what() << std::endl; 
	}
	catch ( OutOfRange &e )	{
		std::cerr << e.what() << std::endl; 
	}
	
    return 0;
}