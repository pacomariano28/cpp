#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {}

Cat::Cat(const Cat &other) : Animal(other) {}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat(void) {}

void Cat::makeSound(void) const {
	std::cout << "Miaw" << std::endl;
}