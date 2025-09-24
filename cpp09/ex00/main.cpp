#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

    if(argc == 1)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    if(argc != 2){
        std::cout << "Error: invalid argument." << std::endl;
        return 0;
    }
    BitcoinExchange btc;
    std::string argvFile = argv[1];
    btc.simulasyonStarted(argvFile);
}