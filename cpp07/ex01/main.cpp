/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:59:15 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:59:16 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(){
    int array[] = {1,2,3,4,5};

    iter(array,5,print);
    std::cout << std::endl;
   
    iter(array,5,square);
    iter(array,5,print);
    std::cout << std::endl;

    std::string famous[] = {"monica","rach","joe","chandler","ross"};
    iter(famous,5,print);

}