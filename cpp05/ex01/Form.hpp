/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:39:15 by itulgar           #+#    #+#             */
/*   Updated: 2025/05/05 15:45:22 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSign;
		const int signGrade;
		const int executeGrade;
	public:
		Form();
		Form(std::string _name, int _signGrade, int _executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string getName() const;
		int getSignGrade() const;
		int getExcuteGrade() const;


		class GradeTooHighException : public std::exception{
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);




#endif