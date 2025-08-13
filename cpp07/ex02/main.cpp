/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:59:48 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:59:49 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){

    try
    {
        Array<int> emptyArr;
        std::cout << "boş dizinin boyutu: " << emptyArr.size() << std::endl;

        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.size(); i++)
            numbers[i] = i * 10;
        
        std::cout << "numbers dizisi: ";
        for (unsigned int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        
        const Array<int>& constNumbers = numbers;
        std::cout << "constNumbers[2] = " << constNumbers[2] << std::endl;

        std::cout << numbers[10] << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
}