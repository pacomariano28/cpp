#include "Zombie.hpp"

int main(void) {
    int     n = 100;
    Zombie* horde = zombieHorde(n, "paquito");

    for(int i = 0; i < n; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}