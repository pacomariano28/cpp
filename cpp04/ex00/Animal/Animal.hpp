#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
	std::string __type;

	public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal(void);

	std::string const & getType() const;
	virtual void makeSound(void) const;
};

#endif