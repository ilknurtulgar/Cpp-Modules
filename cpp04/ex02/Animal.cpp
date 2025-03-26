#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Undefined";
    std::cout << "Animal default constructor called! 🐿" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Animal copy constructor called! 🐿" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator has been called! 🐿" << std::endl;
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal has been destroyed! 🐿" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "just animal voice 🐿" << std::endl;
}