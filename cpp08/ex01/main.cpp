/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:09:28 by itulgar           #+#    #+#             */
/*   Updated: 2025/09/02 15:49:58 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(){  
	
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
			
		std::cout << "sp: " << sp.shortestSpan() << std::endl;
		std::cout << "sp: " << sp.longestSpan() << std::endl;
		std::cout << "----------------------" << std::endl;
		
		Span sp2 = Span(10);
    
		std::vector<int> cont;
		cont.push_back(10);
		cont.push_back(30);
		cont.push_back(38);    
		
		sp2.addNumbers(cont.begin(), cont.end());    
		
		std::cout << "sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2: " << sp2.longestSpan() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	  
	
}