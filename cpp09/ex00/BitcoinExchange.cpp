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
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }
    
    std::string line;
    if(!std::getline(inputFile,line) || !std::getline(csvFile,line)){
            std::cout <<  "Error: empty file." << std::endl;
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

std::string BitcoinExchange::trim(std::string& str){

    size_t first = str.find_first_not_of(" \t");
    if(first == std::string::npos)
      return  "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first,last-first +1);

}

bool BitcoinExchange::isValidValue(std::string& value){
   std::string val = trim(value);
    
   if(val.empty()){
        std::cout << "Error: bad input => (empty)" << std::endl;
        return false;
   }

   try
   {
    double num = std::stoi(val);
    if(num <= 0){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if(num > 1000)
        throw std::out_of_range("value > 1000");
    return true;
   } catch(const std::out_of_range&)
   {
        std::cout << "Error: too large a number." << std::endl;
        return false;

   } catch(const std::invalid_argument&){
        std::cout << "2Error: bad input => " << val << std::endl;
        return false;
   }
}

bool BitcoinExchange::isValidDate(std::string& date){
   
    std::stringstream ss(date);
    std::string day;
    std::string month;
    std::string year;
    
    if(!(std::getline(ss,year,'-') && std::getline(ss,month,'-') && std::getline(ss,day)))
       return false;
    
    day = trim(day);
    month = trim(month);
    year = trim(year);
    int dayI = std::stoi(day);
    int monthI = std::stoi(month);
    int yearI = std::stoi(year);

    int maxDays = 31;

    if (yearI < 1 || (monthI < 1 || monthI > 12) || dayI < 1)
        return false;
    if(monthI == 4 || monthI == 6 || monthI == 9 || monthI == 11)
        maxDays = 30;
    else if (monthI == 2){
        bool isCorrect = (yearI % 4 == 0 && (yearI % 100 != 0 || yearI % 400 == 0));
        maxDays = isCorrect ? 29 : 28;
    }

    if(dayI > maxDays)
        return false;
    return true;
}

void BitcoinExchange::handleInputFile(std::ifstream& inputFile){
    std::string line;
    while(getline(inputFile,line)){
        std::stringstream ss(line);
        std::string date;
        std::string value;

        if(line.find('|') == std::string::npos){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(std::getline(ss,date,'|') && std::getline(ss,value)){
            date = trim(date);
            value = trim(value);
        
         if(!isValidDate(date) ){
            std:: cout << "Error: bad input => " << date << std::endl; 
            continue;
        }
        if(!isValidValue(value))
            continue;
        
        std::map<std::string, double>::iterator it = data.lower_bound(date);
        double dataValue;

        if(it != data.end() && it->first == date){
            dataValue = it->second;
        }else {
            if(it == data.begin()){
                std::cout << "Error: no earlier date." << std::endl;
                continue; 
            }
            --it;
            dataValue = it->second;
        }
       
        double inpValue = std::stod(value);
        std::cout << date << " => " << inpValue << " = " << inpValue * dataValue << std::endl;
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
}