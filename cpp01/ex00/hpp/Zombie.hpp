#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <ostream>

class Zombie {
private:
    std::string __name;

public:
    Zombie(const std::string &name);

    void        announce(void);
    std::string getName(void);
};

Zombie*     newZombie(std::string name);
void        randomChump(std::string name);

#endif