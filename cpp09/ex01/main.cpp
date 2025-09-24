#include "RPN.hpp"

int main(int argc, char** argv){

    if(argc != 2){
        std::cerr << "Error" << std::endl;
        return 0;
    }

    RPN rpn;
    rpn.execute(argv[1]);
}