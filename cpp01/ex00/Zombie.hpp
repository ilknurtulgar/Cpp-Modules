/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:19:56 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/23 18:56:00 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
   std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif