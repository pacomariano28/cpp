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
            if (b > 0 && a > INT_MAX - b) throw OutOfRangeException();
            if (b < 0 && a < INT_MIN - b) throw OutOfRangeException();
            return a + b;

        case '-':
            if (b < 0 && a > INT_MAX + b) throw OutOfRangeException();
            if (b > 0 && a < INT_MIN + b) throw OutOfRangeException();
            return a - b;

        case '*':
            if (a != 0 && (b > INT_MAX / a || b < INT_MIN / a)) throw OutOfRangeException();
            return a * b;

        case '/':
            if (a == INT_MIN && b == -1) throw OutOfRangeException();
            return a / b;

        default: throw InvalidArgException();
    }

}

void processOperation(std::string& token, std::stack<int>& rpnStack) {
    
	if (rpnStack.size() < 2) 
		throw LackOfNumbersException();

    int b = rpnStack.top();
	rpnStack.pop();
	
    int a = rpnStack.top();
	rpnStack.pop();

    switch(token[0]) {
        case '+': rpnStack.push(inRange(a, b, '+')); break;
        case '-': rpnStack.push(inRange(a, b, '-')); break;
        case '*': rpnStack.push(inRange(a, b, '*')); break;
        case '/':
            if (b == 0) throw DivisionByZeroException();
            rpnStack.push(inRange(a, b, '/'));
            break;
    }
}


void calc(int ac, char** av) {

	if (ac != 2)
		throw LackOfArgumentsException();

    std::stack<int> 	rpnStack;
    std::string 		strInput(av[1]);
    std::istringstream 	iss(strInput);
    std::string 		token;

    while (iss >> token) {

        switch(tokenType(token)) {
            case NUMBER: 	rpnStack.push(std::atoi(token.c_str())); 	break;
            case OPERATOR: 	processOperation(token, rpnStack); 			break;
            case INVALID:   throw InvalidArgException();
        }

    }

    if (rpnStack.size() != 1)
        throw ArgsLeftException();

    std::cout << rpnStack.top() << std::endl;
}


int main(int ac, char** av) {

	try  {	
		calc(ac, av);
	}
	catch (LackOfArgumentsException &e) { std::cerr << e.what() << std::endl; }
	catch (LackOfNumbersException &e) 	{ std::cerr << e.what() << std::endl; }
	catch (InvalidArgException &e)		{ std::cerr << e.what() << std::endl; }
	catch (DivisionByZeroException &e)	{ std::cerr << e.what() << std::endl; }
	catch (ArgsLeftException &e)		{ std::cerr << e.what() << std::endl; }
	catch (OutOfRangeException &e)		{ std::cerr << e.what() << std::endl; }
	
    return 0;
}