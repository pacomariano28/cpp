#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../../Weapon/Weapon.hpp"

class HumanA {
	private:
	const std::string&	__name;
	Weapon&				__weapon;

	public:
	HumanA(const std::string& name, Weapon& weapon);
	const	std::string& getName(void) const;
	const	std::string& getWeapon(void) const;
	void	attack(void) const;
};

#endif