/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:07:05 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/26 16:09:15 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T>
typename  T::iterator easyfind(T& contr, int value){
   typename T::iterator it = std::find(contr.begin(),contr.end(),value);
    if(it == contr.end())
       throw std::runtime_error("value not found honey");
    return it;
}

#endif