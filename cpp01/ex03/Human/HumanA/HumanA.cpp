#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : __name(name) , __weapon(weapon) {};

const	std::string& HumanA::getName(void) const {
	return __name;
}

const	std::string& HumanA::getWeapon(void) const {
	return __weapon.getType();
}

void	HumanA::attack(void) const {
	std::cout << __name << " attacks with their " << __weapon.getType() << std::endl;
}