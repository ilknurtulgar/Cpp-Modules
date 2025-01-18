#include "PhoneBook.hpp"

bool isNumber(std::string str)
{
  unsigned long i = 0;
   while(i < str.length()){
    if(str[i]>= '0' && str[i]<= '9')
        return 1;
    i++;
   }
   return 0;
}

int check_identifier(int type, std::string input)
{
    if (type == 1 || type == 2 || type == 3 | type == 5)
    {
        if (!isNumber(input))
            return 1;
    }
    else if (type == 4)
        return isNumber(input);
    return 0;
}

void phoneBook::fill_validate(Contact &contact, std::string name, int type)
{
    while (1)
    {
        std::string input;
        std::cout << name;
        getline(std::cin, input);
        if (!input.empty() && check_identifier(type, input))
        {
            switch (type)
            {
            case 1:
                contact.setFirstName(input);
                break;
            case 2:
                contact.setLastName(input);
                break;
            case 3:
                contact.setNickname(input);
                break;
            case 4:
                contact.setPhoneNumber(input);
                break;
            case 5:
                contact.setDarkestSecret(input);
                break;
            }
            break;
        }
        else
            std::cout << "Please try again!" << std::endl;
    }
}

void phoneBook::add()
{
    Contact newContact;
    fill_validate(newContact, "First Name: ", 1);
    fill_validate(newContact, "Last Name: ", 2);
    fill_validate(newContact, "Nickname: ", 3);
    fill_validate(newContact, "Phone Number: ", 4);
    fill_validate(newContact, "Darkest Secret: ", 5);
    this->person[index] = newContact;
    this->index = (this->index + 1) % 8;
    if (this->contactCount < 8)
        this->contactCount++;
}

void phoneBook::search()
{
    if (this->contactCount == 0)
    {
        std::cout << this->contactCount << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "     index| First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int i = 0;
    while (i < this->contactCount)
    {
        std::cout << std::setw(10) << i << "|"
                    << std::setw(10) << (person[i].getFirstName().size() > 10 ? person[i].getFirstName().substr(0, 10) + "." : person[i].getFirstName()) << "|"
                    << std::setw(10) << (person[i].getLastName().size() > 10 ? person[i].getLastName().substr(0,10) + "." : person[i].getLastName()) << "|"
                    << std::setw(10) << (person[i].getNickname().size() > 10 ? person[i].getNickname().substr(0, 10) + "." : person[i].getNickname()) << "|" << std::endl;
        i++;
    }
    while (1)
    {
        std::cout << "Enter the contact index you want to select: ";
        std::string input;
        getline(std::cin, input);
        if (!input.empty() && !isNumber(input))
        {
            std::cout << "Invalid input! Please enter a number" << std::endl;
            continue;
        }
        int selectedIndex = std::atoi(input.c_str());
        if (selectedIndex >= 0 && selectedIndex < this->contactCount)
        {
            std::cout << "First Name: " << person[selectedIndex].getFirstName() << std::endl;
            std::cout << "Last Name: " << person[selectedIndex].getLastName() << std::endl;
            std::cout << "Nickname: " << person[selectedIndex].getNickname() << std::endl;
            std::cout << "Phone Number: " << person[selectedIndex].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << person[selectedIndex].getDarkestSecret() << std::endl;
            return;
        }
        else{
            std::cout << "Invalid index!" << std::endl;
            continue;
        }
    }
}

void phoneBook::exit()
{
    std::cout << "Program is terminated. See you <3" << std::endl;
   std:: exit(0);
}
