#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat default constructor called! 🐱" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    *this = other;
    std::cout << "Cat copy constructor called! 🐱" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator has been called! 🐱" << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat has been destroyed! 🐱" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow meow! 🐱" << std::endl;
}