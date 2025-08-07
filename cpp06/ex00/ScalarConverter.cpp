/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:47:20 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 14:59:55 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& literal){
	
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	
	 if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
		
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " <<  std::fixed << std::setprecision(1) << d << std::endl;		
		return;
		
    } else if (literal == "nan" || literal == "nanf" || 
			literal == "+inf" || literal == "-inf" || 
			literal == "+inff" || literal == "-inff"){
		

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;

			if (literal == "nan" || literal == "nanf") {
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;

			} else if (literal == "+inf" || literal == "+inff") {
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;

			} else if (literal == "-inf" || literal == "-inff") {
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			return;

	} 
	
	std::string clean = literal;

	if(clean[clean.length() - 1] == 'f')
		clean = clean.substr(0,clean.length() - 1);

	std::stringstream ss(clean);
	ss >> d;

	if(ss.fail() || !ss.eof()){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	if(d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;	
	
	if(d < static_cast<double>(std::numeric_limits<int>::max()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << "f" << std::endl;
	std::cout << "double: "  <<  static_cast<double>(d) << std::endl;	
}
