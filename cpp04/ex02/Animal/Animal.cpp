#include "Animal.hpp"

Animal::Animal(void) : __type("Furro") {
	std::cout << __type << " is here thanks to animal constructor!" << std::endl;
}

Animal::Animal(const std::string type) : __type(type) {
	std::cout << __type << " is here thanks to animal constructor!" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << __type << " is here thanks to copy constructor!" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other)
		__type = other.__type;
	std::cout << __type << " is here thanks to = operator!" << std::endl;
	return *this;
}

Animal::~Animal(void) {
	std::cout << __type << " is dead >:)" << std::endl;
}

std::string const & Animal::getType() const {
    return __type;
}

// removed makeSound function because is an abstract class