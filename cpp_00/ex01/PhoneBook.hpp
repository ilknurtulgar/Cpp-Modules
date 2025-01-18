#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>
using namespace std;

class phoneBook
{
private:
    Contact person[8];
   int index;
   int contactCount;

public:
   phoneBook() : index(0), contactCount(0) {};
   void add();
void fill_validate(Contact& contact,std::string name,int type);
   void search();
   void exit();
};



#endif