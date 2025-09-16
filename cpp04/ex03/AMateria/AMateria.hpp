#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class AMateria
{
	protected:
	std::string __type;
	
	public:
	AMateria(std::string const & type) : __type(type) {} ;
	std::string const & getType() const { return __type; };
	AMateria& operator=(const AMateria &other) {
		if (this != &other)
			__type = other.__type;
		return *this;
	}
	virtual ~AMateria() {};

	virtual AMateria* clone() const = 0;
	/* como esta funcion sabemos que se va a ovverridear 100%, 
	casteamos para eliminar el warning y nos ahorramos el .cpp*/
	virtual void use(ICharacter& target) { (void)target; };
};

#endif
