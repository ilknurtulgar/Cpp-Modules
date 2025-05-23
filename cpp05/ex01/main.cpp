/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:24:00 by itulgar           #+#    #+#             */
/*   Updated: 2025/05/23 14:40:47 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice",50);
		Bureaucrat bob("Bob",10);

		Form taxform("tax declaration",30,5);
		
		std::cout << taxform << std::endl;
		
		std::cout << "alice tries to sign the form: " << std::endl;
		alice.signForm(taxform);
		std::cout << "form after signing: " << std::endl;
		std::cout << taxform << std::endl;
		
		std::cout << "---------------------------------------" << std::endl;
		
		std::cout << "form after signing: " << std::endl;
		std::cout << taxform << std::endl;
		
		std::cout << "bob tries to sign the form: " << std::endl;
		bob.signForm(taxform);
		
		std::cout << "form after signing: " << std::endl;
		std::cout << taxform << std::endl;
	
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return 0;
}