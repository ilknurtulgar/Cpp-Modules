/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:07:57 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/23 18:48:42 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << "Weapon " << type << " has been created!" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon " << type << " destroyed!" << std::endl;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    return this->type;
}
