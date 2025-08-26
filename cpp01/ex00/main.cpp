#include "../hpp/Zombie.hpp"

int main(void) {
    Zombie* ara = newZombie("ara");

    ara->announce();
    std::cout << "Deleting " << ara->getName() << std::endl;
    delete(ara);

    Zombie* prema = newZombie("prema");
    prema->announce();
    std::cout << "Deleting " << prema->getName() << std::endl;
    delete(prema);

    randomChump("antonimo");

    return 0;
}