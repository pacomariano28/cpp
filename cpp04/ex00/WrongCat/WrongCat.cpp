#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    _type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "Miaw Miaw (wrong!)" << std::endl;
}
