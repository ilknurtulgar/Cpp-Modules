/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:31:45 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/26 15:31:51 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc,char **argv)
{
	if(argc != 2)
		return std::cout << "Invalid number argument! 🦭" << std::endl,0;
	Harl harl;
	harl.complain(argv[1]);
}