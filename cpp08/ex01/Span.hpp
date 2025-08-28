/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:12:05 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/26 16:27:58 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
	private:
		unsigned int N;
		std::vector<int> container;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int value);
		int shortestSpan();
		int longestSpan();

		template <typename T>
		void addNumbers(T begin, T end){
			for (T it = begin; it != end; ++it)
			{
				if(container.size() >= N)
					throw std::runtime_error("span is full honey");
				container.push_back(*it);
			}
		}

};

#endif