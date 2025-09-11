#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(const Dog &other) : Animal(other) {}
Dog& Dog::operator=(const Dog &other) : Aninal::operator=(other) {}
virtual ~Dog() : Animal::~Animal() {} // ??????????????'

virtual void makeSound(void) const {

}