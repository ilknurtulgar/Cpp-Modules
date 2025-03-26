#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called 🐶" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
    std::cout << "Dog copy constructor called! 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator has been called! 🐶" << std::endl;
    if(this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog has been destroyed! 🐶" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof woof! 🐶" << std::endl;
}