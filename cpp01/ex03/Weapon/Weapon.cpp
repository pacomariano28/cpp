#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType) : __type(weaponType) {};

const std::string&	Weapon::getType(void) const {
	return __type;
}

void				Weapon::setType(const std::string& newType) {
	__type = newType;
}