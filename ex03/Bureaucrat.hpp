/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:03:56 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:04:51 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

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
	void signForm(AForm *f) const;
	void executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return  "GradeTooHigh" ; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return  "GradeTooLow" ; }
	};

};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif