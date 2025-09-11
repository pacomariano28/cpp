#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <ostream>
#include <iostream>

class ClapTrap {
    protected:
    std::string     __name;
    unsigned int    __health;
    unsigned int    __energy;
    unsigned int    __damage;

    public:
    ClapTrap(void);
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};


#endif