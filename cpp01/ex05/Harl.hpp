/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:25:46 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/25 15:36:27 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
private:
	std::string level;
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl(std::string lvl);
	~Harl();
	void complain( std::string level);
};


#endif