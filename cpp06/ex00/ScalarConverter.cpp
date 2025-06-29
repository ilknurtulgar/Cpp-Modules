#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&  other){
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}



void ScalarConverter::convert(const std::string& literal){



    if(literal.length() == 1 && !isdigit(literal[0]) ){

    }
    //char, int, float, double

}