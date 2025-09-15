#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	__brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	__brain = new Brain(*(other.__brain));
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		*__brain = *(other.__brain);
	}
	return *this;
}

Dog::~Dog(void) {
	delete __brain;
}

void Dog::makeSound(void) const {
	std::cout << "Wau Wau amego" << std::endl;
}

Brain* Dog::getBrain(void) const { 
	return __brain; 
}
