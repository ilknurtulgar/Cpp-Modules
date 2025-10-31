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

void PmergeMe::run(int ac, char **av){
    
}