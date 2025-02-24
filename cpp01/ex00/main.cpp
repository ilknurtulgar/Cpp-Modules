/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:19:34 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/20 15:26:29 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("zombie");
    zombie.announce();
    
    randomChump("random champ zombie");
    
    Zombie *zb;
    zb = newZombie("new zombie");
    zb->announce();
    delete zb;

    return 0;
}