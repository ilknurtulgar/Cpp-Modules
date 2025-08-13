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

template <typename T,typename F>
void iter(T* array,size_t lenght, F func){
    for (size_t i = 0; i < lenght; i++)
        func(array[i]);
}


#endif