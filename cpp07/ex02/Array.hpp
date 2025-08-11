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
#define MAX_VAL 750

template <typename T>
class Array
{
    private:
        T* array;
        unsigned int lenght;
    public:
        Array();
        Array(T* array, unsigned int lenght);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        //eleman erişimi
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        //dizinin elaman sayısını döndürmesi için
        unsigned int size() const;

};




#endif