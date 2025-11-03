#include "Span/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    // Prueba básica
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(42);
    } catch (std::exception& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    Span bigSpan(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i)
        v.push_back(rand());
    bigSpan.addNumbers(v.begin(), v.end());

    std::cout << "bigSpan shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "bigSpan longest: " << bigSpan.longestSpan() << std::endl;

    Span emptySpan(1);
    emptySpan.addNumber(42);
    try {
        std::cout << emptySpan.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}