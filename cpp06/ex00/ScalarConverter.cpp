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
    if(literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
        return true;
    return false;
}

bool ScalarConverter::isFloat(const std::string& literal){
    if(literal.back() == 'f')
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
    }
    return DOUBLE;
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
    std::string tmp = literal;
    tmp.pop_back();
    std::stringstream ss(tmp);
    if (ss >> f && ss.eof())
        return f;
    else
        throw ScalarConverter::InvalidArgumentException();
}

const char* ScalarConverter::InvalidArgumentException::what() const throw(){
    return "Invalid argument format";
}

void ScalarConverter::char_print(){
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string& literal){
    
    if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        char_print();
        return;
    } else
    {
        try
        {
             LiteralType type = whichLiteralType(literal);
            switch (type)
            {
            case SPECIAL:
                //c,i = 0 impossible
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
                break;
            case INT:
            i = ScalarConverter::stoi(literal);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            // if(literal[0] == '0')
            //     c = NON;
            //     else
            //         c = static_cast<char>(d);
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
            }
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
    
    // std::cout << "char: " << c << std::endl;
    // std::cout << "int: " << i << std::endl;
    // std::cout << "float: " << f << std::endl;  
    // std::cout << "double: " << d << std::endl;
}