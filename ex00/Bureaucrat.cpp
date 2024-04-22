/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:02:51 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:10:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n), grade(g) 
{
    std::cout << "Full constructor called" << std::endl;
    if (grade < 1) 
        throw GradeTooHighException();
    if (grade > 150) 
        throw GradeTooLowException();
    std::cout  << name << " my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade) 
{
    std::cout << "Copy constructor called" << std::endl;
    std::cout  << name << " my grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() 
{ 
    std::cout << "Bureaucrat destructor" << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) 
{
    std::cout << "Assignation" << std::endl;
    if (this != &copy) 
    {
        grade = copy.grade;
    }
    return *this;
}

int Bureaucrat::getGrade() const 
{ 
    return grade; 
}

std::string Bureaucrat::getName() const 
{ 
    return name; 
}

void Bureaucrat::incrementGrade() 
{
    std::cout << "Incrementing " << name << std::endl;
    if (grade <= 1) 
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() 
{
    std::cout << "Decrementing " << name << std::endl;
    if (grade >= 150) 
        throw GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) 
{
    o << b.getName() << "  grade " << b.getGrade();
    return o;
}
