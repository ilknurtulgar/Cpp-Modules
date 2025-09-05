#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

    if(argc != 2){
        std::cout << "Invalid argument honey" << std::endl;
        return 0;
    }
    BitcoinExchange btc;
    std::string argvFile = argv[1];
    btc.simulasyonStarted(argvFile);
    std::cout << "yes of course" << std::endl;
}