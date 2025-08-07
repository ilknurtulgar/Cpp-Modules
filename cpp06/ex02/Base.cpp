/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:25:54 by itulgar           #+#    #+#             */
/*   Updated: 2025/08/07 18:26:50 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(){}

Base* generate(void){
    
	std::srand(std::time(NULL));
	
	int randI;
	randI = std::rand() % 3;
	
	if(randI == 0)
		return new A();
	else if (randI == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p){

	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	
	if(a != NULL)
		std::cout << "A class pointer" << std::endl;
	else if(b !=NULL)
		std::cout << "B class pointer" << std::endl;
	else if(c !=NULL)
		std::cout << "C class pointer" << std::endl;
		
}

void identify(Base& p){
	
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A class referance" << std::endl;
	}
	catch(const std::exception& e){}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B class referance" << std::endl;
	}
	catch(const std::exception& e){}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C class referance" << std::endl;
	}
	catch(const std::exception& e){}
}