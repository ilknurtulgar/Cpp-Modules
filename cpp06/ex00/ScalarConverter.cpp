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

// std::string whichLiteralType(const std::string& literal){

//     std::string literalType[6] = {"nan","nanf","+inf","-inf","+inff","-inff"};
//     for (int i = 0; i < 6; i++)
//     {
//         if(literal == literalType[i])
//             return literalType[i];
//     }
//     return "";
// }

void ScalarConverter::convert(const std::string& literal){

    //static_cast<type>(expression)
    //char, int, float, double
    //isChar, isInt, isFloat, isDouble
    //nan,nanf, -inff,+inff,-inf,+inf
    if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else {
         c = 0;
         i = 0;

         if(literal == "nan" || literal == "nanf"){
            f = std::nanf("");
            d = std::nan("");

         } else if(literal == "+inf" || literal == "+inff"){
            f = std::numeric_limits<float>::infinity();
            d = std::numeric_limits<double>::infinity();

         } else if(literal == "-inf" || literal == "-inff"){
            f = -std::numeric_limits<float>::infinity();
            d = -std::numeric_limits<double>::infinity();
      }

    }
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;  
    std::cout << "double: " << d << std::endl;  
    //std::cout << literal << std::endl;

}