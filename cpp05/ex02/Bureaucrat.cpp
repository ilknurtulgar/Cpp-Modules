/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:23:58 by itulgar           #+#    #+#             */
/*   Updated: 2025/05/23 14:16:40 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none"), grade(150)
{
	std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->grade = other.getGrade();
		
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}


void Bureaucrat::gradeIncrement()
{
	if(this->getGrade() - 1 < 1){
		std::cout << getGrade();
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;

}

void Bureaucrat::gradeDecrement()
{
	if(this->getGrade() + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout<< name << " couldn't execute "<< form.getName() << " because " << e.what() << '\n';

	}
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout<< name << " couldn't sign "<< form.getName() << " because " << e.what() << '\n';
		 
	}
}