#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clapclap");
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << std::endl;
    std::cout << "🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢"<< std::endl << std::endl;


    ScavTrap scav("Scavscav");
    scav.attack("enemy");
    scav.guardGate();

    std::cout << std::endl;
    std::cout << "🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢"<< std::endl << std::endl;


    FragTrap frag("Fragfrag");
    frag.attack("enemy");
    frag.highFivesGuys();

    std::cout << std::endl;
    std::cout << "🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢🦢"<< std::endl << std::endl;


}