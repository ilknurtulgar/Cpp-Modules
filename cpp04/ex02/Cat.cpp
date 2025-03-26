#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat default constructor called! 🐱" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called! 🐱" << std::endl;
    brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator has been called! 🐱" << std::endl;
    if(this != &other)
    {
        delete brain;
        this->type = other.type;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat has been destroyed! 🐱" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow meow! 🐱" << std::endl;
}

void Cat::printBrainAdresses()
{
    std::cout << this->brain << std::endl;
}

void Cat::setCatIdeas(std::string ideas)
{
    this->brain->setIdeas(ideas);
}

void Cat::printCatIdeas(int i)
{
   this->brain->printBrainIdeas(i);
}