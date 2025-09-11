#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : __name("undefined") , __health(10), __energy(10), __damage(0) {
    //std::cout << "ClapTrap " << __name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : __name(name) , __health(10), __energy(10), __damage(0){
    //std::cout << "ClapTrap " << __name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    if (this != &other)
        *this = other;
    //std::cout << "ClapTrap " << __name << " created by copy constructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this !=& other) {
		__name = other.__name;
		__health = other.__health;
		__energy = other.__energy;
		__damage = other.__damage;
	}

    return *this;
}

ClapTrap::~ClapTrap(void) {
    //std::cout << "ClapTrap " << __name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (target.empty()) {
		std::cout << __name << " cannot attack an empty target!" << std::endl;
		return;
	}

	if (__energy < 1) {
		std::cout << __name << " does not have enough energy points to attack." << std::endl;
		return;
	}

	__energy--;
	std::cout << __name << " attacks " << target << " causing " << __damage << " points of damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (__health == 0) {
		std::cout << __name << " is already dead and cannot take more damage." << std::endl;
		return;
	}

	__health = (__health > amount) ? (__health - amount) : 0;
	std::cout << __name << " has been attacked and lost " << amount << " health points." << std::endl;

	if (__health == 0)
		std::cout << __name << " has died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
    if (__health <= 0) {
		std::cout << __name << " is death, cannot be repaired." << std::endl;
		return;
	}

	if (__energy < 1) {
		std::cout << __name << " does not have enough energy points to repair." << std::endl;
		return;
	}

	__health = (__health + amount <= 10) ? __health + amount : 10;
	__energy--;
	std::cout << __name << " restored " << amount << " of health." << std::endl;
}