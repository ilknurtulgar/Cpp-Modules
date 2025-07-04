#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
#include <iomanip>
#include <sstream>

#define NON 2
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
        void printConvert();
        class InvalidArgumentException : public std::exception{
            const char* what() const throw();
        };

    public:
        static void convert(const std::string& literal);
};




#endif