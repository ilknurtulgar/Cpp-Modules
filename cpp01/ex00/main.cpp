/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:19:34 by itulgar           #+#    #+#             */
/*   Updated: 2025/03/05 14:17:00 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zombie("zombie");
    Zombie *zb;
    zb = newZombie("new zombie");
    zb->announce();
    delete zb;
    zombie.announce();
    
    randomChump("random champ zombie");
    

    return 0;
}