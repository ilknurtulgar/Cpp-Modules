#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other){
    *this = other;
}

RPN &RPN::operator=(const RPN& other){
    if(this != &other){
        this->container = other.container;
    }
    return *this;
}

RPN::~RPN(){}

void RPN::execute(const std::string& argv){
    std::stringstream ss(argv);
    std::string key;

    while(ss >> key){
        if(key == "+" || key == "-" || key == "*" || key == "/"){
            
            if(container.size() < 2){
                std::cerr << "Error" << std::endl;
                return;
            }
            
            int x = container.top();
            container.pop();
            int y = container.top();
            container.pop();

            if(key == "+")
                container.push(y + x);
            else if(key == "-")
                container.push(y - x);
            else if(key == "*")
                container.push(y * x);
            else {
                if(x == 0){
                    std::cerr << "Error" << std::endl;
                    return;
                }
                container.push(y / x);
            }

        }else{
            try
            {
                int num =  std::stoi(key);
                container.push(num);
            }
            catch(const std::invalid_argument&)
            {
                std::cerr << "Error" << std::endl;
                return;
            }catch(const std::out_of_range&){
                std::cerr <<  "Error" << std::endl;
                return;
            }
        }
    }
    if(container.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    
    std::cout << container.top() << std::endl;
}