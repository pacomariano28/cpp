#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"

int main() {
	/* 
	We changed Animal to abstract class with one 
	full virtual method, so this next does not work now
	
	Animal paco;
	paco.makeSound(); 
	*/

	Dog *paco = new Dog(); 
	paco->makeSound();

	delete paco;

    return 0;
}
