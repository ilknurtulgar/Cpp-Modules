/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:37:43 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/15 18:37:45 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::cout << PINK << "~ PhoneBook ~" << DEFAULT << std::endl;
    PhoneBook newPhoneBook;
    while(1){
    std::string input;
    std::cout << "Please use ADD, SEARCH, EXIT commands: ";
    getline(std::cin,input);
    if(std::cin.eof())
        return 0;
    if(input == "ADD")
    {
        if(!newPhoneBook.add())
            return 0;
    }
    else if (input == "SEARCH")
    {
        if(!newPhoneBook.search())
            return 0;
    }
    else if (input == "EXIT")
        newPhoneBook.exit();
    else
        std::cout << "Invalid commnad! Try again." << std::endl;
    }
}