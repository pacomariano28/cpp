#include "Human/HumanA/HumanA.hpp"
#include "Human/HumanB/HumanB.hpp"
#include "Weapon/Weapon.hpp"

int main()
{
	std::string name = "payko";

	Weapon club = Weapon("crude spiked club");
	HumanA bob(name, club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
return 0;
}