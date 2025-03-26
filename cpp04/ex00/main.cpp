#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
    
        std::cout << std::endl;
    
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
    
        std::cout << std::endl;
    
        i->makeSound();
        j->makeSound();
        meta->makeSound();
    
        std::cout << std::endl;
        delete meta;
        delete i;
        delete j;
    }

    std::cout << std::endl;
    std::cout << "rivrivrivrivrivrivrivrivrivrivrivrivriv" << std::endl;
    std::cout << std::endl;
    
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
    
        std::cout << std::endl;
    
        std::cout << meta->getType() << " " << std::endl;
        std::cout << cat->getType() << " " << std::endl;
    
        std::cout << std::endl;
    
        meta->makeSound();
        cat->makeSound();
    
        std::cout << std::endl;
        delete meta;
        delete cat;
    }

    return 0;
}