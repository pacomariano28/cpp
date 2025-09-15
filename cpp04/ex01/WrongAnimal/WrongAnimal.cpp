#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
    std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

std::string const & WrongAnimal::getType(void) const {
    return this->_type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Some wrong animal sound..." << std::endl;
}
