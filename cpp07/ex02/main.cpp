#include "Array.hpp"
#include "Array.tpp"
#include <iostream>
#include <string>

int main() {
    // Array vacío
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    // Array de enteros
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = (i + 1) * 10;

    std::cout << "numbers: ";
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Copy constructor
    Array<int> copy(numbers);
    copy[0] = 999;
    std::cout << "copy: ";
    for (unsigned int i = 0; i < copy.size(); ++i)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    std::cout << "numbers (should be unchanged): ";
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Assignment operator
    Array<int> assign;
    assign = numbers;
    assign[1] = 888;
    std::cout << "assign: ";
    for (unsigned int i = 0; i < assign.size(); ++i)
        std::cout << assign[i] << " ";
    std::cout << std::endl;

    // Prueba de excepción
    try {
        std::cout << "Intentando acceso fuera de rango..." << std::endl;
        std::cout << numbers[10] << std::endl; // Debe lanzar excepción
    } catch (Array<int>::OutOfRange& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    // Prueba con strings
    Array<std::string> words(3);
    words[0] = "Hola";
    words[1] = "Mundo";
    words[2] = "42";
    std::cout << "words: ";
    for (unsigned int i = 0; i < words.size(); ++i)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    return 0;
}