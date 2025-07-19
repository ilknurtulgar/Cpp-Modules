/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:47:20 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/14 19:55:53 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0.0f;
double ScalarConverter::d = 0.0;

ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&  other){
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isInt(const std::string& literal){
    if(literal.find('.') == std::string::npos && literal.find('f') == std::string::npos){
        for (size_t i = 0; i >= literal.size(); i++)
        {
            if (literal[0] == '-' || literal[0] == '+')
                    i++;
            if(!isdigit(literal[i]))
                    return false;
        }
        return true;
    }
    return false;
}

bool ScalarConverter::isFloat(const std::string& literal){
    if(literal[literal.size() - 1] == 'f')
        return true;
    return false;
}

bool ScalarConverter::isDouble(const std::string& literal){
	if(ScalarConverter::stod(literal))
		return true;
	return false;
}

LiteralType ScalarConverter::whichLiteralType(const std::string& literal)
{

    std::string literalType[6] = {"nan","nanf","+inf","-inf","+inff","-inff"};
    for (int i = 0; i < 6; i++)
    {
        if(literal == literalType[i])
            return SPECIAL;
    }
    if (isInt(literal)){
        return INT;
    }else if (isFloat(literal)){
            return FLOAT;
    } else if (isDouble(literal))
		return DOUBLE;
    return RANDOM;
}

double ScalarConverter::stod(const std::string& literal){
    double d;
    std::stringstream ss(literal);
    if (ss >> d && ss.eof())
        return d;
    else
        throw ScalarConverter::InvalidArgumentException();
}

int ScalarConverter::stoi(const std::string& literal)
{
    int i;
    std::stringstream ss(literal);
    if (ss >> i && ss.eof())
        return i;
    else
        throw ScalarConverter::InvalidArgumentException();

}

float ScalarConverter::stof(const std::string& literal)
{
    float f;
    std::string tmp = literal.substr(0,literal.size() - 1);
    std::stringstream ss(tmp);
    if (ss >> f && ss.eof())
        return f;
    else
        throw ScalarConverter::InvalidArgumentException();
}

const char* ScalarConverter::InvalidArgumentException::what() const throw(){
    return "Invalid argument format";
}

void ScalarConverter::print(){

}

void ScalarConverter::special_check_print_f(){
	
	if(std::isnan(f)){
			std::cout << "float: nanf" << std::endl;
	}
		else if(f == std::numeric_limits<float>::infinity())
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
			
}

void ScalarConverter::special_check_print_d(){
	
	if(std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if(d == std::numeric_limits<double>::infinity())
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
			
}

void ScalarConverter::special_print(){
	
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if(f)
		special_check_print_f();
	special_check_print_d();
	
}

void ScalarConverter::convert(const std::string& literal){
    
    if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
		print();
    } else
    {
        try
        {
            LiteralType type = whichLiteralType(literal);
            switch (type)
            {
            case SPECIAL:
                c = 0;
                i = 0;
                
                if(literal == "nan" || literal == "nanf"){
                    f = nanf("");
                    d = nan("");
                    
                } else if(literal == "+inf" || literal == "+inff"){
                    f = std::numeric_limits<float>::infinity();
                    d = std::numeric_limits<double>::infinity();
                    
                } else if(literal == "-inf" || literal == "-inff"){
                    f = -std::numeric_limits<float>::infinity();
                    d = -std::numeric_limits<double>::infinity();
                }
				special_print();
				return;
            case INT:
            i = ScalarConverter::stoi(literal);
            if(i < 32 || i > 126)
                c = NON;
			else
            	c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
                break;
            case FLOAT:
                f = ScalarConverter::stof(literal);
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
                break;
            case DOUBLE:
                d = ScalarConverter::stod(literal);
                c = static_cast<char>(d);
                i = static_cast<int>(d);
                f = static_cast<float>(d);                
                break;
            case RANDOM:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                return;
            }
		if(c == NON)
		    std::cout << "char: Non displayable" << std::endl;
	    else
    	std::cout << "char: '" << c << "'" << std::endl;
      if(literal.find('.') != std::string::npos)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
          if(tmp.find('.') != std::string::npos)
            std::cout << "float: " << f << "f" << std::endl;
        else
            std::cout << "float: " << f << ".0f" << std::endl;
    
    std::cout << "int: " << i << std::endl;
        }
        catch(const std::exception& e)
        {
            c = 0;
            i = 0;
            f = 0;
            d = 0;
            std::cerr << e.what() << '\n';
        }
        
    }
}