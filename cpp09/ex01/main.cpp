#include "RPN.hpp"


//> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

int main(int argc, char** argv){

    if(argc != 2){
        std::cout << "Error" << std::endl;
        return;
    }

    RPN rpn;
    rpn.execute();
}