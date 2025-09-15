#ifndef CAT_HPP
#define CAT_HPP

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public Animal {
	private:
	Brain *__brain;

	public:
	Cat(void);
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	virtual ~Cat(void);

	void makeSound(void) const;
	Brain* getBrain(void) const;
};

#endif