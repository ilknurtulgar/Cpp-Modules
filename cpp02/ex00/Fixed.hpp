/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:50:23 by itulgar           #+#    #+#             */
/*   Updated: 2025/03/05 14:50:25 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int fixedPoint;
        static const int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator = (const Fixed &fixed);
        void setRawBits( int const raw );
        int getRawBits( void ) const;
};



#endif