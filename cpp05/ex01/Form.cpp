/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:37:48 by itulgar           #+#    #+#             */
/*   Updated: 2025/05/23 14:23:33 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("none"), signGrade(0),executeGrade(0)
{
	std::cout << "default constructor called" << std::endl;
}

Form::Form(const std::string _name, int _signGrade, int _executeGrade) : name(_name), signGrade(_signGrade), executeGrade(_executeGrade)
{
	this->isSign = false;
	if (signGrade < 1 || executeGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(signGrade > 150 || executeGrade > 150)
		throw Bureaucrat::GradeTooLowException();	

}

Form::Form(const Form& other) : name(other.getName()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{
	*this = other;
}

Form& Form::operator=(const Form& other) 
{
	if(this != &other){
		this->isSign = other.isSign;
	}
	return *this;	
}

Form::~Form()
{}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::string Form::getName() const 
{
	return this->name;
}

int Form::getSignGrade() const 
{
	return this->signGrade;
}

int Form::getExecuteGrade() const 
{
	return this->executeGrade;
}

bool Form::getIsSign() const
{
	return this->isSign;
}
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " ,signGrade " << form.getSignGrade() << " ,executeGrade " << form.getExecuteGrade() << " ,isSign " << form.getIsSign();
	return out;
}
