#ifndef DOG_HPP
#define DOOG_HPP

#include "../Animal/Animal.hpp"

class Dog : public Animal {
	public:
	Dog(void);
	Dog(const Dog &other);
	Dog& operator=(const Dog &other);
	virtual ~Dog();

	virtual void makeSound(void) const;
};

#endif