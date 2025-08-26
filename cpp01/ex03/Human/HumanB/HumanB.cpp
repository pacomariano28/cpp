#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : __name(name), __weapon(NULL){};

const	std::string& HumanB::getName(void) const {
	return __name;
}

const	std::string& HumanB::getWeapon(void) const {
	if (__weapon)
		return __weapon->getType();
	const std::string& noWeapon = "no weapon";
	return noWeapon;
}

void	HumanB::setWeapon(Weapon& weapon) {
	__weapon = &weapon;
}

void	HumanB::attack(void) const {
	if (__weapon)
		std::cout << __name << " attacks with their " << __weapon->getType() << std::endl;
	else
		std::cout << __name << " can't attack because there is no weapon available." << std::endl;
}