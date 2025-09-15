#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {}

Dog::Dog(const Dog &other) : Animal(other) {}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog(void) {}

void Dog::makeSound(void) const {
	std::cout << "Wau Wau amego" << std::endl;
}