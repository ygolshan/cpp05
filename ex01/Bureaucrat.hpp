/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:02:06 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:04:51 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat 
{
private:
	std::string const name;
	int grade;
	Bureaucrat();
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &copy);

	int getGrade() const;
	std::string getName() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form *f) const;

	class GradeTooHighException : public std::exception 
	{
	public:
		virtual const char* what() const throw() { return  "GradeTooHigh" ; }
	};

	class GradeTooLowException : public std::exception 
	{
	public:
		virtual const char* what() const throw() { return  "GradeTooLow" ; }
	};

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif