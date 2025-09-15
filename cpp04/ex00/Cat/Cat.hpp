#ifndef CAT_HPP
#define CAT_HPP

#include "../Animal/Animal.hpp"

class Cat : public Animal {
	public:
	Cat(void);
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	virtual ~Cat(void);

	void makeSound(void) const;
};

#endif