/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:33:28 by itulgar           #+#    #+#             */
/*   Updated: 2025/06/18 18:33:37 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    std::cout << "default constructor called" << std::endl;
}

Intern::Intern(const Intern &other){
    *this = other;
}

Intern& Intern::operator=(const Intern &other){
    if(this != &other)
        return *this;
    return *this;
}

Intern::~Intern(){}

const char* Intern::FormNotFoundException::what() const throw(){
    return "Form not found!";
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target){
 
    std::string formTypes[3] = {"robotomy request","presidential pardon","shrubbery creation"};
    AForm* forms[3] = {new RobotomyRequestForm(target),new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
    
    for(int i = 0; i < 3; i++){
        if(formName == formTypes[i]){
            std::cout << "Intern creates " << formTypes[i] << std::endl;

            for (int j = 0; j <3; ++j)
            {
                if (j !=i)
                  delete forms[j];
            }
            
            return forms[i];   
        }
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];

    throw FormNotFoundException();

}