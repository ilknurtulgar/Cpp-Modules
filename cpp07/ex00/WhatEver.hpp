/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:56:24 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:58:31 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> 
void swap(T &a, T &b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b){
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b){
    return a > b ? a : b;
}

#endif