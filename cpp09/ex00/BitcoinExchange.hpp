#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
        bool isOpenFiles(std::ifstream& inputFile, std::ifstream& csvFile);
        void readCSV(std::ifstream& csvFile);
        void handleInputFile(std::ifstream& inputFile);
        std::string trim(std::string& str);
        bool isValidDate(std::string& date);
        bool isValidValue(std::string& value);

        public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
       
        void simulasyonStarted(std::string& argvFile);
        
};


#endif