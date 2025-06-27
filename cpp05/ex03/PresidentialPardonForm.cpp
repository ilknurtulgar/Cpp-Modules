/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:57:11 by itulgar           #+#    #+#             */
/*   Updated: 2025/06/18 17:57:17 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5), target("default"){
    std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm",25,5), target(target) {
    std::cout << getTarget() << " sign 25, execute 5" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if(this != &other)
        AForm::operator=(other);
    this->target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::action(void) const {
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}