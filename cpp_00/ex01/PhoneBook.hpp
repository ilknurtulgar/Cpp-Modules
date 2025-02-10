#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>


class phoneBook
{
private:
    Contact person[8];
   int index;
   int contactCount;

public:
   phoneBook() : index(0), contactCount(0) {};
   int add();
int fill_validate(Contact& contact,std::string name,int type);
   int search();
   void exit();
};



#endif