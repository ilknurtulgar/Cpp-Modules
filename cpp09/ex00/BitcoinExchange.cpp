#include  "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if(this != &other){
        this->data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}


bool BitcoinExchange::isOpenFiles(std::ifstream& inputFile, std::ifstream& csvFile){
    if(!inputFile.is_open() || !csvFile.is_open()){
        std::cout << "couldn't open file honey" << std::endl;
        return false;
    }
    
    std::string line;
    if(!std::getline(inputFile,line) || !std::getline(csvFile,line)){
            std::cout <<  "Empty file honey" << std::endl;
            
            return false;
    }
    
    return true;
}

void BitcoinExchange::readCSV(std::ifstream& csvFile){

    std::string line;
    while(std::getline(csvFile,line)){
        std::stringstream ss(line);
        std::string date;
        std::string value;

        if(std::getline(ss,date,',') && std::getline(ss,value))
            data[date] = atof(value.c_str());
    }
    csvFile.clear();
    csvFile.seekg(0,std::ios::beg);


}

std::string trim(std::string& str){

    size_t first = str.find_first_not_of(" \t");
    if(first == std::string::npos)
      return  "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first,last-first +1);

}

bool BitcoinExchange::isValidValue(std::string& value){

}

bool BitcoinExchange::isValidDate(std::string& date){

}

void BitcoinExchange::handleInputFile(std::ifstream& inputFile){
    std::string line;
    while(getline(inputFile,line)){
        std::stringstream ss(line);
        std::string date;
        std::string value;

        if(std::getline(ss,date,'|') && std::getline(ss,value)){
            date = trim(date);
            value = trim(value);

         if(isValidDate(date) && isValidValue(value)){
            //burada csvdeki date bulup value ile carp yazdır
          }else
            continue;
        }

    }
}

void BitcoinExchange::simulasyonStarted(std::string& argvFile){
    std::ifstream inputFile(argvFile.c_str());
    std::ifstream csvFile("data.csv");
    
    if(!isOpenFiles(inputFile,csvFile))
        return;
    readCSV(csvFile);
    handleInputFile(inputFile);

    // for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); ++it)
    // {
    //      std::cout << it->first << " => " << it->second << std::endl;
    //      return ;
    // }
   

}