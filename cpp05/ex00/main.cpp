/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:24:00 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/14 20:14:50 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		
		// Bureaucrat bure;
		// std::cout << bure << std::endl;
		// bure.gradeDecrement();

		Bureaucrat bureaucratOne("İlknur",0);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat bureaucratTwo("istanbul",160);

	}
	catch(const std::exception& e)
	{
		std::cerr << "error: " << e.what() << '\n';
	}
	
	return 0;
	
}