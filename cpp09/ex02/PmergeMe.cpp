#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other){
    if(this != &other){
        this->dequeCont = other.dequeCont;
        this->vectCont = other.vectCont;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}


void PmergeMe::parserContainer(int ac, char **av){
    for (int i = 1; i < ac; i++)
    {
        std::string arv = av[i];
       if(!std::all_of(arv.begin(), arv.end(), ::isdigit))
            throw std::invalid_argument("invalid input");

       long num = std::stol(arv);
       if(num < 0)
            throw std::invalid_argument("invalid input");

        if (num > INT_MAX)
            throw std::out_of_range("invalid input");
        vectCont.push_back(num);
        dequeCont.push_back(num);
    }
}



void PmergeMe::run(int ac, char **av){
   parserContainer(ac,av);
//    sorterVector();
//    sorterDeque();
    std::cout << "returns honey" << std::endl; 
}