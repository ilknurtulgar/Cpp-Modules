
# include "ScalarConverter.hpp"

int main(int argc, char **arg){
    if(argc != 2)
        return std::cout << "Invalid argument count!" ,0;
    ScalarConverter::convert(arg[1]);
}

