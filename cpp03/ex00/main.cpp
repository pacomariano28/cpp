#include "ClapTrap/ClapTrap.hpp"

int	main(void) {
	ClapTrap 	trap("Antonio");
	std::string	enemy = "Pedro Pascal";

	trap.attack(enemy);
	trap.takeDamage(20);
	trap.beRepaired(10);
}