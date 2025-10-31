#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <chrono>
#include <climits>
#include <stdexcept>

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

        void run(int ac, char **av);
        void parserContainer(int ac, char **av);
        // void sorterVector();
        // void sorterDeque();
};


#endif