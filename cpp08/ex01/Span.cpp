/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:11:55 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/26 16:27:15 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other){
    *this = other;
}

Span& Span::operator=(const Span& other){
    
    if(this != &other){
        this->N = other.N;
        this->container = other.container;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int value){

    if(container.size() >= N)
        throw std::runtime_error("there is no more space honey");
    container.push_back(value);
}

int Span::shortestSpan(){

    if(container.size() < 2)
        throw std::runtime_error("the number range can not be calc honey");
    // 3,5,6,9,11,17

   std::vector<int> sortedCon = container;
   std::sort(sortedCon.begin(), sortedCon.end());

   int minSpan = sortedCon[1] - sortedCon[0];

   for (size_t i = 0; i < sortedCon.size() - 1; i++)
   {
        int calc = sortedCon[i + 1] - sortedCon[i];
        if(calc < minSpan)
            minSpan = calc;
   }
    return minSpan;
}

int Span::longestSpan(){

    if (container.size() < 2)
        throw std::runtime_error("the number range can not be calc honey");

    int maxValue = *std::max_element(container.begin(),container.end());
    int minValue = *std::min_element(container.begin(),container.end());
    
    return maxValue - minValue;     
}