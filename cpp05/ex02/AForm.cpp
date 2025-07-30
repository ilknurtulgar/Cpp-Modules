/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:40:44 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/30 15:11:06 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("none"),isSign(false), signGrade(150),executeGrade(150) 
{
	std::cout << "default constructor called" << std::endl;
}

AForm::AForm(const std::string _name, int _signGrade, int _executeGrade) : name(_name), signGrade(_signGrade), executeGrade(_executeGrade)
{
	this->isSign = false;
	if (signGrade < 1 || executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(signGrade > 150 || executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();	

}

AForm::AForm(const AForm& other) : name(other.getName()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other) 
{
	if(this != &other){
		this->isSign = other.isSign;
	}
	return *this;	
}

AForm::~AForm()
{}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	
	if(bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::string AForm::getName() const 
{
	return this->name;
}

int AForm::getSignGrade() const 
{
	return this->signGrade;
}

int AForm::getExecuteGrade() const 
{
	return this->executeGrade;
}

bool AForm::getIsSign() const
{
	return this->isSign;
}

void AForm::execute(Bureaucrat const &executor) const 
{
	if(!this->getIsSign())
		throw  AForm::FormNotSignedException();
	else if(executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	this->action();
}
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " ,signGrade " << form.getSignGrade() << " ,executeGrade " << form.getExecuteGrade() << " ,isSign " << form.getIsSign();
	return out;
}
