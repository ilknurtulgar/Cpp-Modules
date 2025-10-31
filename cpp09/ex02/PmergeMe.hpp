#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <chrono>

class PmergeMe
{
    private:
        std::vector<int> vectCont;
        std::deque<int> dequeCont;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe& other);
        PmergeMe(char **av);
        
        void run(int ac, char **av);
};



#endif