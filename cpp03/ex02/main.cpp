#include "FragTrap/FragTrap.hpp"

int	main(void) {
	FragTrap 	trap("Antonio");
	std::string	enemy = "Pedro Pascal";

	trap.attack(enemy);
	trap.takeDamage(20);
	trap.beRepaired(10);
	trap.highFivesGuys();
}