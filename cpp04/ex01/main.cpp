#include "Animal/Animal.hpp"
#include "Dog/Dog.hpp"
#include "Cat/Cat.hpp"

int main() {
    const int size = 51;
    Animal* animals[size];

    // Creamos mitad Dogs y mitad Cats
    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Probando makeSound ---\n";
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Probando deep copy ---\n";
    Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea(0, "Comer");
    Dog dog2 = *dog1; // copy constructor deep copy

    std::cout << "dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

    dog2.getBrain()->setIdea(0, "Dormir");
    std::cout << "Después de cambiar dog2:" << std::endl;
    std::cout << "dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

    delete dog1;

    std::cout << "\n--- Borrando array de animales ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}
