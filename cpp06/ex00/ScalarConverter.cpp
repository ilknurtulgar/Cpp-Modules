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

bool whichLiteralType(const std::string& literal, std::string& loc){

    std::string literalType[6] = {"nan","nanf","+inf","-inf","+inff","-inff"};
    for (int i = 0; i < 6; i++)
    {
        if(literal == literalType[i]){
            loc = literalType[i];
            return true;
        }
    }
    return false;
}

double ScalarConverter::stod(const std::string& literal){
    double d;
    std::stringstream ss(literal);
    if (ss >> d && ss.eof())
        return d;
    else
        throw ScalarConverter::InvalidArgumentException();
}

const char* ScalarConverter::InvalidArgumentException::what() const throw(){
    return "Invalid argument format";
}

void ScalarConverter::convert(const std::string& literal){
    
    std::string loc;
    if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);

    } else if(whichLiteralType(literal,loc)) {
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
        
    }else {
            try
            {
               d = ScalarConverter::stod(literal);
               if(literal[0] == '0')
                   c = NON;
                else
                    c = static_cast<char>(d);
                
                i = static_cast<int>(d);
                f = static_cast<float>(d);
                
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
   // printConvert();
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;  
    std::cout << "double: " << d << std::endl;
}