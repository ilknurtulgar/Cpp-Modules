#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        
    public:
        ScavTrap();
        ScavTrap(std::string nm);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator = (const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};


#endif