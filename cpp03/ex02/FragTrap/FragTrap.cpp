#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "Fragtrap " << __name << " created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	__health = 100;
	__energy = 100;
	__damage = 30;

    std::cout << "Fragtrap " << __name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
   if (this != &other)
		ClapTrap::operator=(other);

    std::cout << "FragTrap " << __name << " created by operator =" << std::endl;
    return *this;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap " << __name << " created by copy constructor" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << __name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << __name << " requests a positive high five!" << std::endl;
}