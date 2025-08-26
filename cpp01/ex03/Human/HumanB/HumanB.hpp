#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "../../Weapon/Weapon.hpp"

class HumanB {
	private:
	const std::string	__name;
	Weapon*				__weapon;

	public:
	HumanB(const std::string& name);
	const	std::string& getName(void) const;
	const	std::string& getWeapon(void) const;
	void	setWeapon(Weapon& weapon);
	void	attack(void) const;
};

#endif