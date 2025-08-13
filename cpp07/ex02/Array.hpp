/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:59:45 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:59:46 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
    T* array;
    unsigned int lenght;
    public:
    Array();
    Array(unsigned int len);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
    
    class OutOfException : public std::exception {
        const char* what() const throw();
    };
    
};

#include "Array.tpp"

#endif