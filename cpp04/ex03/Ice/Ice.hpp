#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria/AMateria.hpp"

class Ice : public AMateria {
	public:
	Ice() : AMateria("ice") {}
	Ice(const Ice &other) : AMateria(other) {}
	Ice& operator=(const Ice &other) {
		if (this != &other)
			AMateria::operator=(other);
		return *this;
	}
	
};

#endif