/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:47:29 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/04 19:19:53 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include <sstream>
# include <cmath>
# include <limits>

#define NON 2

enum LiteralType {
    FLOAT,
    INT,
    DOUBLE,
    SPECIAL,
	RANDOM
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
		
    public:
        static void convert(const std::string& literal);
};




#endif