#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    std::cout << "WrongCat default constructor called! 🐱" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    *this = other;
    std::cout << "WrongCat copy constructor called! 😿" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator has been called! 😿" << std::endl;
    if(this != &other)
        WrongAnimal::operator=(other);
    return *this;
   
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat has been destroyed! 😿" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meow meow! 😿" << std::endl;
}