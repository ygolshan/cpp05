/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:03:41 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:04:51 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const int toSign;
	const int toExec;
	bool isSigned;
	AForm();

public:
	AForm(std::string &n, int &gts, int &gte);
	AForm(std::string n, int gts, int gte);
	AForm(AForm const &f);
	virtual ~AForm();

	AForm &operator=(AForm const &ref);

	std::string getName() const;
	int getToSign() const;
	int getToExec() const;
	bool getIsSigned() const;
	void setSigned(bool s);

	virtual void beSigned(Bureaucrat const &b);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() { return  "GradeTooHigh" ; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() { return  "GradeTooLow" ; }
	};

	class FormNotSigned : public std::exception {
	public:
		virtual const char* what() const throw() { return  "Formulary was not signed" ; }
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &b);

#endif