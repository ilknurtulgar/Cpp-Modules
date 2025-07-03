#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
#include <iomanip>



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
       
    public:
        static void convert(const std::string& literal);
};




#endif