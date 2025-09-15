#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	__brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	__brain = new Brain(*(other.__brain));
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other){
		Animal::operator=(other);
		*__brain = *(other.__brain);
	}
	return *this;
}

Cat::~Cat(void) {
	delete __brain;
}

void Cat::makeSound(void) const {
	std::cout << "Miaw" << std::endl;
}

Brain* Cat::getBrain(void) const { 
	return __brain; 
}
