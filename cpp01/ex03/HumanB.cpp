/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:12:04 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/23 18:50:54 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), weapon(NULL) 
{
	std::cout << "HumanB " << this->_name << " has been created!" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << this->_name << " destroyed!" << std::endl;
}


void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if(this->weapon == NULL)
		std::cout << this->_name << " attacks with their hands" << std::endl;  
	else
		std::cout << this->_name << " attacks with their " << this->weapon->getType() << std::endl;  
}

