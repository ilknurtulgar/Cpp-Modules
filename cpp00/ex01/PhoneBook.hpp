/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:29:40 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/15 14:44:52 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>


class PhoneBook
{
private:
    Contact person[8];
   int index;
   int contactCount;
   int fill_validate(Contact& contact,std::string name,int type);
   bool isNumber(std::string str);
   int check_identifier(int type, std::string input);

public:
   PhoneBook() : index(0), contactCount(0) {};
   int add();
   int search();
   void exit();
};



#endif