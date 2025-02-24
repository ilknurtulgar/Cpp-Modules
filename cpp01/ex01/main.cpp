/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:56:16 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/20 19:24:48 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N;
    N = 3;
    
    Zombie *horde;
    horde = zombieHorde(N,"zombiee");

    for(int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
    return 0;
}