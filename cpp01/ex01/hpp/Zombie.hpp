#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <ostream>
#include <string>

class Zombie {

    private:
    std::string __name;

    public:
    Zombie();
    Zombie(const std::string& name);
    
    void        announce(void);
    std::string getName(void);
    void        setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);
#endif