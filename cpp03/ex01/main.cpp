#include "ScavTrap/ScavTrap.hpp"

int	main(void) {
	ScavTrap 	trap("Antonio");
	std::string	enemy = "Pedro Pascal";

	trap.attack(enemy);
	trap.takeDamage(20);
	trap.beRepaired(10);
}