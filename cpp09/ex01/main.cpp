#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

enum eTokenType {
    NUMBER,
    OPERATOR,
    INVALID
};

#define INVALID_ARG         "Error: invalid argument"
#define DIVISOR_0           "Error: cannot divide by 0"
#define NOT_ENOUGH_NUMBERS  "Error: needed at least 2 numbers to operate"
#define MORE_ARGS_LEFT      "Error: there is still more args to be processed"

static eTokenType tokenType(const std::string& token) {
    if (token.length() == 1 && std::isdigit(token[0])) {
        return NUMBER;
    }

    if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")) {
        return OPERATOR;
    }
    return INVALID;
}

void processOperation(std::string& token, std::stack<int>& rpnStack) {
    if (rpnStack.size() < 2) {
        std::cerr << NOT_ENOUGH_NUMBERS << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int b = rpnStack.top();
    rpnStack.pop();

    int a = rpnStack.top();
    rpnStack.pop();

    if (token == "+")
        rpnStack.push(a + b);
    else if (token == "-")
        rpnStack.push(a - b);
    else if (token == "*")
        rpnStack.push(a * b);
    else if (token == "/") {
        if (b == 0) {
            std::cerr << DIVISOR_0 << std::endl;
            exit(EXIT_FAILURE);
        }
        rpnStack.push(a / b);
    }
}

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: diff params. Usage ./RPN 'values'" << std::endl;
        return EXIT_FAILURE;
    }

    std::stack<int> rpnStack;
    std::string strInput = av[1];
    std::istringstream iss(strInput);
    std::string token;

    while (iss >> token) {

        switch(tokenType(token)) {
            case NUMBER:    rpnStack.push(std::atoi(token.c_str()));
                break;
            case OPERATOR:  processOperation(token, rpnStack);
                break;
            case INVALID:   std::cerr << INVALID_ARG << std::endl;
                return EXIT_FAILURE;
        }

    }

    if (rpnStack.size() != 1) {
        std::cerr << MORE_ARGS_LEFT << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << rpnStack.top() << std::endl;

    return 0;
}