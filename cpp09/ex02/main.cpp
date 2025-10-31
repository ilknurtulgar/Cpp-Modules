#include "PmergeMe.hpp"

int main(int ac, char **av){
    
    if(ac < 2){

        std::cerr << "Error";
        return 0;
    }
    try
    {
        PmergeMe sorter;
        sorter.run(ac,av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}