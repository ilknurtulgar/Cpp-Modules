/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:10:50 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/23 18:45:39 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) 
{
	std::cout << "HumanA " << this->name << " has been created!" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << this->name << " destroyed!" << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
