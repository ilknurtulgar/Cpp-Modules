#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called 🥷" << std::endl;
}

ClapTrap::ClapTrap(std::string nm) : name(nm), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "ClapTrap " << name << " has been created! 🥷" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap " << name << " copy constructor called! 🥷" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator has been called! 🥷" << std::endl;
    if(this !=&other)
    {
        this->name = other.name;
        this->attackDamage = other.attackDamage;
        this->energyPoints = other.energyPoints;
        this->hitPoints = other.hitPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed! 🥷" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
					<< this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }else
        std::cout << "ClapTrap " << this->name << " could not damage" << target << ", causing "
                                << this->attackDamage << "because of it has no attack damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount; 
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClaptTrap " << name << " has no energy or hit points left to repair itself!" << std::endl;

}