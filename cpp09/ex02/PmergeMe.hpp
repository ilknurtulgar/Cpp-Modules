#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <climits>
#include <stdexcept>
#include <iomanip>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> vectCont;
        std::deque<int> dequeCont;

        double vectTime;
        double deqTime;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);

        void run(int ac, char **av);
        void parserContainer(int ac, char **av);
        void sorterVector(std::vector<int>& v);
        void sorterDeque(std::deque<int>&d);

        template <typename T>
        void printContainer(T& con){
        for (size_t i = 0; i < con.size(); ++i)
            std::cout << con[i] << " ";
        std::cout << std::endl;
        }

        template <typename T>
        void printProcessingTime(const T& con,const std::string& name,double time){
            std::cout << "Time to process a range of " << con.size() << " elements with std::[" << name << "]"
                      << " : " << time << " us" << std::endl;
        }
};


#endif