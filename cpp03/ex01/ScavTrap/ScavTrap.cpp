#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	__health = 100;
	__energy = 50;
	__damage = 20;

	std::cout << "ScavTrap " << __name << " created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << __name << " created by copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
		
	std::cout << "ScavTrap " << __name << " created by operator =" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << __name << " destroyed!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << __name << " is now in Gate keeper mode" << std::endl;
}