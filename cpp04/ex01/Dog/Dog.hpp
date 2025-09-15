#ifndef DOG_HPP
#define DOG_HPP

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public Animal {
	private:
	Brain *__brain;

	public:
	Dog(void);
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	virtual ~Dog(void);

	void makeSound(void) const;
	Brain* getBrain(void) const;
};

#endif