#include "../hpp/Zombie.hpp"

Zombie::Zombie(const std::string &name) : __name(name) {}

void    Zombie::announce(void) {
    std::cout << __name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) {
    return __name;
}