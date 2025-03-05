/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:51:27 by itulgar           #+#    #+#             */
/*   Updated: 2025/03/05 14:52:13 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed
{
	private:
		int fixedPoint;
		const static int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& fixed);
		Fixed& operator = (const Fixed &fixed);
	
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif