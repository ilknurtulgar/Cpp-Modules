#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called! 🐛" << std::endl;   
}

FragTrap::FragTrap(std::string nm) : ClapTrap(nm)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout <<  "FragTrap " << name << " has been created! 🐛" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap" << name << " copy constructor called! 🐛" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator has been called! 🐛" << std::endl;
    
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " has been destroyed! 🐛" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ": high five guys!" << std::endl;
}