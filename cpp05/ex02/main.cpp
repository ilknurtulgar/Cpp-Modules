/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:36:29 by itulgar           #+#    #+#             */
/*   Updated: 2025/06/18 17:43:01 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    // Bureaucrat bob("bob",1);
    // ShrubberyCreationForm form("home");

    Bureaucrat emma("emma",3);
    RobotomyRequestForm robotForm("robot");

    try
    {
        // bob.signForm(form);
        // bob.executeForm(form);

        emma.signForm(robotForm);
        emma.executeForm(robotForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}