#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    //Animal* animal = new Animal();
    {
        std::cout << "DOG SCOPE 🐶" << std::endl;

        Dog* j = new Dog();
        Dog* copyJ = new Dog(*j);
    
        std::cout << std::endl;
    
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        j->setDogIdeas("huhuhu");

        std::cout << "What is dog thinking?" << std::endl;
        j->printDogIdeas(2);
        std::cout << std::endl;


        std::cout << "Original Dog Brain:" << std::endl;
        j->printBrainAdresses();

        std::cout << "Copy Dog Brain:" << std::endl;
        copyJ->printBrainAdresses();

        std::cout << std::endl;
        delete j;
        delete copyJ;
    }

    std::cout << std::endl;
    std::cout << "rivrivrivrivrivrivrivrivrivrivrivrivriv" << std::endl;
    std::cout << std::endl;

    {
        std::cout << "CAT SCOPE 🐱" << std::endl;
        Cat* i = new Cat();
        Cat* copyI = new Cat(*i);

    
        std::cout << std::endl;
    
        std::cout << i->getType() << " " << std::endl;
    
        std::cout << std::endl;
    
        i->makeSound();

        std::cout << std::endl;

        i->setCatIdeas("mimimi");

        std::cout << "What is cat thinking?" << std::endl;
        i->printCatIdeas(2);
        std::cout << std::endl;


        std::cout << "Original Cat Brain:" << std::endl;
        i->printBrainAdresses();

        std::cout << "Copy Cat Brain:" << std::endl;
        copyI->printBrainAdresses();

        std::cout << std::endl;
        delete copyI;
        delete i;
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