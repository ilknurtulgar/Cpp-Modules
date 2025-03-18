#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called! 🪩" << std::endl;
}

ScavTrap::ScavTrap(std::string nm) : ClapTrap(nm) 
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout <<  "ScavTrap " << name << " has been created! 🪩" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap" << name << " copy constructor called! 🪩" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator has been called! 🪩" << std::endl;
    
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " has been destroyed! 🪩" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
					<< this->attackDamage << " points of damage! 🪩" << std::endl;
        this->energyPoints--;
    }else
        std::cout << "ClapTrap " << this->name << " could not damage" << target << ", causing "
                                << this->attackDamage << "because of it has no attack damage! 🪩" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode! 🪩" << std::endl;
}