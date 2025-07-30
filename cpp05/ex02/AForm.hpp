/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:41:37 by itulgar           #+#    #+#             */
/*   Updated: 2025/07/30 15:04:40 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
# include <iostream>


class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSign;
		const int signGrade;
		const int executeGrade;
	public:
		AForm();
		AForm(std::string _name, int _signGrade, int _executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getIsSign() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const &executor)const;
		virtual void action() const = 0;
		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);




#endif