/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:47:29 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/14 19:52:46 by itulgar          ###   ########.fr       */
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
        static char c;
        static int i;
        static float f;
        static double d;
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();


        static double stod(const std::string& literal);
        static float stof(const std::string& literal);
        static int stoi(const std::string& literal);
        static LiteralType whichLiteralType(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
	
		static void special_print();
		static void special_check_print_f();
		static void special_check_print_d();
        static void print();
		
        class InvalidArgumentException : public std::exception{
            const char* what() const throw();
        };

    public:
        static void convert(const std::string& literal);
};




#endif