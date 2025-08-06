/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:23:00 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/14 15:34:08 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data dataWater;
    dataWater.i = 22;
    dataWater.c = 'i';
    
    Data* dataGlass = &dataWater;

    uintptr_t raw = Serializer::serialize(dataGlass);
    

    Data* deserializes = Serializer::deserialize(raw); 

    if(dataGlass == deserializes)
        std::cout << "Pointers are same 🪩" << std::endl;
    else
        std::cout << "Pointers are different 🤯" << std::endl;

    std::cout << "dataglass->i : " << dataGlass->i << std::endl;
    std::cout << "dataglass->c : " << dataGlass->c << std::endl;
    std::cout << std::endl;

    std::cout << "deserializes->i : " << deserializes->i << std::endl;
    std::cout << "deserializes->c : " << deserializes->c << std::endl;

    
}