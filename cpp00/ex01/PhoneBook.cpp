/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:46:23 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/15 15:32:39 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::isNumber(std::string str)
{
  unsigned long i = 0;
  int a = 0;
   while(i < str.length())
   {
        if(!(str[i]>= '0' && str[i]<= '9'))
            a = 1;
        i++;
   }
   if(a == 1)
        return 0;
   return 1;
}

int PhoneBook::check_identifier(int type, std::string input)
{    
    if (type == 4)
        return isNumber(input);
    return 1;
}

int PhoneBook::fill_validate(Contact &contact, std::string name, int type)
{
    while (1)
    {
        std::string input;
        std::cout << name;
        getline(std::cin, input);
        if(std::cin.eof())
            return 0;
        if (!input.empty() && check_identifier(type,input))
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
    return 1;
}

int PhoneBook::add()
{
    Contact newContact;
    if(!fill_validate(newContact, "First Name: ", 1) ||
    !fill_validate(newContact, "Last Name: ", 2) ||
    !fill_validate(newContact, "Nickname: ", 3) ||
    !fill_validate(newContact, "Phone Number: ", 4) ||
    !fill_validate(newContact, "Darkest Secret: ", 5))
        return 0;
    this->person[index] = newContact;
    this->index = (this->index + 1) % 8;
    if (this->contactCount < 8)
        this->contactCount++;
    return 1;
}

int PhoneBook::search()
{
    if (this->contactCount == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return 1;
    }
    std::cout << "     index| First Name| Last Name|  Nickname|" << std::endl;
    std::cout << PINK << "--------------------------------------------" << DEFAULT << std::endl;
    int i = 0;
    while (i < this->contactCount)
    {
        std::cout << std::setw(10) << i << PINK << "|" << DEFAULT
                    << std::setw(10) << (person[i].getFirstName().size() > 10 ? person[i].getFirstName().substr(0, 9) + "." : person[i].getFirstName())  << PINK << "|" << DEFAULT
                    << std::setw(10) << (person[i].getLastName().size() > 10 ? person[i].getLastName().substr(0,9) + "." : person[i].getLastName())  << PINK << "|" << DEFAULT
                    << std::setw(10) << (person[i].getNickname().size() > 10 ? person[i].getNickname().substr(0, 9) + "." : person[i].getNickname())  << PINK << "|" << DEFAULT << std::endl;
        i++;
    }
    while (1)
    {
        std::cout << "Enter the contact index you want to select: ";
        std::string input;
        getline(std::cin, input);
        if(std::cin.eof())
            return 0;
        if (!input.empty() && !isNumber(input))
        {
            std::cout << "Invalid input! Please enter a number" << std::endl;
            continue;
        }
        int selectedIndex = std::atoi(input.c_str());
        if (selectedIndex >= 0 && selectedIndex < this->contactCount)
        {
            std::cout << PINK << "First Name: " << DEFAULT << person[selectedIndex].getFirstName()  << std::endl;
            std::cout << PINK << "Last Name: " << DEFAULT  << person[selectedIndex].getLastName() << std::endl;
            std::cout << PINK << "Nickname: " << DEFAULT <<  person[selectedIndex].getNickname() << std::endl;
            std::cout << PINK << "Phone Number: " << DEFAULT <<  person[selectedIndex].getPhoneNumber()  << std::endl;
            std::cout << PINK << "Darkest Secret: " << DEFAULT << person[selectedIndex].getDarkestSecret()  << std::endl;
            return 1;
        }
        else{
            std::cout << "Invalid index!" << std::endl;
            continue;
        }
    }
    return 1;
}

void PhoneBook::exit()
{
    std::cout << PINK << "Program is terminated. See you <3" << DEFAULT  << std::endl;
   std:: exit(0);
}
