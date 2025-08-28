/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:05:46 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/26 16:09:09 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(){
    
	std::vector<int> ages;
    ages.push_back(10);
    ages.push_back(22);
    ages.push_back(30);
    ages.push_back(35);
    ages.push_back(56);
    ages.push_back(82);

    try
    {
       std::vector<int>::iterator it = easyfind(ages,82);
       std::cout << "value is here honey: " << *it << std::endl;

       std::vector<int>::iterator it2 = easyfind(ages,12);
       std::cout << *it2 << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
    }
    
}
