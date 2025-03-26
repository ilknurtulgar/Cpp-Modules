#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called 🐶" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called! 🐶" << std::endl;
    brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator has been called! 🐶" << std::endl;
    if(this != &other)
    {
        delete brain;
        this->type = other.type;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog has been destroyed! 🐶" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof woof! 🐶" << std::endl;
}

void Dog::printBrainAdresses()
{
    std::cout << this->brain << std::endl;
}

void Dog::setDogIdeas(std::string ideas)
{
    this->brain->setIdeas(ideas);
}

void Dog::printDogIdeas(int i)
{
   this->brain->printBrainIdeas(i);
}