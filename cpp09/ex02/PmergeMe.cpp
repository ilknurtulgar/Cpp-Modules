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
        for (size_t j = 0; j < arv.size(); ++j)
        {
            if(!std::isdigit(static_cast<unsigned char>(arv[j])))
                throw std::invalid_argument("Error");
        }
        
        std::istringstream ss(arv);
        long num;
        ss >> num;

        if(ss.fail())
            throw std::invalid_argument("Error");
       if(num < 0)
            throw std::invalid_argument("Error");

        if (num > INT_MAX)
            throw std::out_of_range("Error");
        
        vectCont.push_back(static_cast<int>(num));
        dequeCont.push_back(static_cast<int>(num));
    }
}

void PmergeMe::sorterVector(std::vector<int>& v){
   //5,2,8,3
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
    vectTime = double(end - start) / CLOCKS_PER_SEC ;
}

void PmergeMe::sorterDeque(std::deque<int>&d){
    clock_t start = clock();
    if(d.size() <= 1)
        return;

    std::deque<int> small;
    std::deque<int> large;
    for (size_t i = 0; i < d.size(); i+=2)
    {
        if(i + 1 < d.size()){
            int a = d[i];
            int b = d[i + 1];
            if(a < b){
                small.push_back(a);
                large.push_back(b);
            }else{
                small.push_back(b);
                large.push_back(a);
            }
        }else
            small.push_back(d[i]);
    }
    sorterDeque(large);

    for (size_t i = 0; i < small.size(); ++i)
    {
        std::deque<int>::iterator pos = std::lower_bound(large.begin(),large.end(),small[i]);
        large.insert(pos,small[i]);
    }
    d = large;
    clock_t end = clock();
    deqTime = double(end - start) / CLOCKS_PER_SEC ;
}

void PmergeMe::run(int ac, char **av){

    vectTime = 0;
    deqTime = 0;
    
    parserContainer(ac,av);
    std::cout << "Before: ";
    printContainer(vectCont);
    sorterVector(vectCont);
    std::cout << "After: ";
    printContainer(vectCont);
    std::cout << std::endl;

    std::cout << "Before: ";
    printContainer(dequeCont);
    sorterDeque(dequeCont);
    std::cout << "After: ";
    printContainer(dequeCont);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(6);
    printProcessingTime(vectCont,"vector",vectTime);
    printProcessingTime(dequeCont,"deque",deqTime);

}