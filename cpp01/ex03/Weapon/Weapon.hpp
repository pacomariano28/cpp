#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
	std::string __type;

	public:
	Weapon(const std::string& weaponType);

	const	std::string&	getType(void) const;
	void	setType(const std::string& newType);
};

#endif