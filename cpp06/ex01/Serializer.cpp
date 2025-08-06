/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:27:54 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/13 16:32:56 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other){
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other){
	(void)other;
	return *this;
}

Serializer::~Serializer(){}

//tam sayı ile pointer değerine dönüştürme işlemi yapıyoruz
//pointerin bellekteki adresini bir tamsayı olarak saklar
uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

//bir tamsayıyı alır data* çevirir.tam sayıya çevirdiği adresi pointer yapar
Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

//bu işlem pointerı tam sayı olarak saklamak veya iletmek istediğimizde: pointerı ağda, dosyada veya farklı bir veri 
//olarak dönüştürmek istediğimizde