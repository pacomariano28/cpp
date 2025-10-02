#include "EasyFind/EasyFind.hpp"
#include "EasyFind/Easyfind.tpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(i * 10);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    std::list<int> l;
    for (int i = 0; i < 5; ++i)
        l.push_back(i * 100);

    try {
        std::list<int>::iterator it = easyfind(l, 200);
        std::cout << "Encontrado en list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(l, 999);
        std::cout << "Encontrado en list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
}