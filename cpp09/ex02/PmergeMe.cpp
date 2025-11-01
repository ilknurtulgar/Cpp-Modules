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

void PmergeMe::sorterVector(std::vector<int>& v){
   //5,2,8,3
   //5,2 8,3
   // 2,5 3,8
   //s 2 3
   // l 5 8

   clock_t start = clock();
   if(v.size() <= 1)
        return;

    std::vector<int> small;
    std::vector<int> large;
    for (size_t i = 0; i < v.size(); i+=2)
    {
        if(i + 1 < v.size()){
            int a = v[i];
            int b = v[i + 1];
            if(a < b){
                small.push_back(a);
                large.push_back(b);
            }else{
                small.push_back(b);
                large.push_back(a);
            }
        }else
            small.push_back(v[i]);
    }

    sorterVector(large);

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(large.begin(),large.end(),small[i]);
        large.insert(pos,small[i]);
    }
    v = large;
    clock_t end = clock();
}

void PmergeMe::run(int ac, char **av){

   parserContainer(ac,av);

    std::cout << "Before: ";
    for (size_t i = 0; i < vectCont.size(); ++i)
        std::cout << vectCont[i] << " ";
    std::cout << std::endl;
   sorterVector(vectCont);

    std::cout << "After: ";
    for (size_t i = 0; i < vectCont.size(); i++)
        std::cout << vectCont[i] << " ";
    std::cout << std::endl;


//    sorterDeque();
    std::cout << "returns honey" << std::endl; 
}