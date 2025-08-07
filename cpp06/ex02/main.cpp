/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:35:38 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 16:52:50 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *base = NULL;
	base = generate();

	///pointer
	identify(base);

	// //referance
	 identify(*base);
	 delete base;
		
}