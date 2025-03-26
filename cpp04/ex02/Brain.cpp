#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called!" << std::endl;
    this->idea = new std::string[100];
}

Brain::Brain(const Brain& other)
{
    
    std::cout << "Brain copy constructor called!" << std::endl;
    this->idea = new std::string[100];
    for(int i = 0; i < 100;i++)
    this->idea[i] = other.idea[i];

}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator has been called!" << std::endl;
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->idea[i] = other.idea[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain has been destroyed!" << std::endl;
    delete [] this->idea;
}

void Brain::setIdeas(std::string ideas)
{
    for(int i = 0; i < 100; i++)
        this->idea[i] = ideas;
}

void Brain::printBrainIdeas(int i)
{
    if(i < 0 || i > 99)
        return;
    for(int j = 0; j < i; j++)
        std::cout << this->idea[j] << std::endl;
}