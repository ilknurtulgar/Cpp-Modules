/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:59:22 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:59:23 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array,int lenght, void (*func)(T&)){
    for (int i = 0; i < lenght; i++)
        func(array[i]);
}

template <typename T>
void print(T& i){
    std::cout << i << " ";
}


template <typename T>
void square(T& i){
    i *= i;
}
#endif