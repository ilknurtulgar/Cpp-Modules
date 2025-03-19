#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("ilkkus");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << std::endl;
    std::cout << "🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢"<< std::endl << std::endl;


    ScavTrap scav("rachel");
    scav.attack("enemy");
    scav.guardGate();
}