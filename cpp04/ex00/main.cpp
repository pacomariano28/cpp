#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"

int main()
{
	const Animal* meta = new Animal();


	const Dog* random = new Dog();
	const Animal* j = new Dog();
	Animal *arr = new Animal[2];


	arr[0] = *random;
	arr[1] = *j;

	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	return 0;
}