#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clapclap");
    clap.attack("clap enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️🧝‍♀️" << std::endl;

    ScavTrap scav("Scavscav");
    scav.attack("scav enemy");
    scav.guardGate();
}