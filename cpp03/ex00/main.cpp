#include "ClapTrap.hpp"

int main()
{
    std::string name = "ilkkus";
    ClapTrap soldier1(name);
    ClapTrap soldier2(soldier1);


    soldier2.attack("Enemy");
    soldier2.takeDamage(3);
    soldier2.beRepaired(2);
    soldier2.attack("Enemy");
    soldier2.takeDamage(100);
    soldier2.beRepaired(2);
    soldier2.attack("Enemy");
}