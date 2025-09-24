#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> container;
    public:
        RPN();
        RPN(const RPN& other);
        RPN operator=(const RPN& other);
        ~RPN();

       void execute();
};




#endif