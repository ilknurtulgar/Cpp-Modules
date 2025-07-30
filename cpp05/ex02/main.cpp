/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:36:29 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/30 15:24:46 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    std::cout << "------------------" << std::endl;
    std::cout << "Shrubbery Creation Form" << std::endl;

    Bureaucrat bob("bob",1);
    ShrubberyCreationForm form("home");

    try
    {
        bob.signForm(form);
        bob.executeForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "------------------" << std::endl;
    std::cout << "Robotomy Request Form" << std::endl;

    Bureaucrat emma("emma",3);
    RobotomyRequestForm robotForm("robot");

    try
    {
        emma.signForm(robotForm);
        emma.executeForm(robotForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "------------------" << std::endl;
    std::cout << "Presidential Pardon Form" << std::endl;

    Bureaucrat monica("monica",4);
    PresidentialPardonForm pardonForm("pardon");

    try
    {
        monica.signForm(pardonForm);
        monica.executeForm(pardonForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}