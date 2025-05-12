/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:24:00 by itulgar           #+#    #+#             */
/*   Updated: 2025/05/05 15:37:44 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Form form1 = Form("basic", 100, 150);
		Bureaucrat a = Bureaucrat("john",140);
		a.signForm(form1);
		Form ff(form1);
		std::cout << ff.getIsSign()<< "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
	
}