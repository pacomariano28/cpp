#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../ClapTrap/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(void);
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap &other);
    ~ScavTrap(void);

    void    guardGate(void);
};

#endif