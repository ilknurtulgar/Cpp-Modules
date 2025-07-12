#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
#include <iomanip>
#include <sstream>

#define NON 2

enum LiteralType {
    FLOAT,
    INT,
    DOUBLE,
    SPECIAL
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
        static void char_print();
        static LiteralType whichLiteralType(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);

        class InvalidArgumentException : public std::exception{
            const char* what() const throw();
        };

    public:
        static void convert(const std::string& literal);
};




#endif