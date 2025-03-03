/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:47:50 by itulgar           #+#    #+#             */
/*   Updated: 2025/03/03 14:47:15 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << *stringPTR << std::endl;
    std::cout << &brain << std::endl;
    std::cout << stringPTR << std::endl;
    
    std::cout << stringREF << std::endl;
    std::cout << &stringREF << std::endl;
}