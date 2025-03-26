#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void printBrainAdresses();
        void makeSound() const;
        void setCatIdeas(std::string ideas);
        void printCatIdeas(int i);
};



#endif