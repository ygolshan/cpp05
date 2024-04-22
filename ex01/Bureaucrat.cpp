/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:01:56 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:08:56 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n), grade(g) 
{
    std::cout << "Bureaucrat Full constructor called" << std::endl;
    if (grade < 1) 
        throw GradeTooHighException();
    if (grade > 150) 
        throw GradeTooLowException();
    std::cout  << name << " my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade) 
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    std::cout  << name << " my grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() 
{ 
    std::cout << "Bureaucrat destructor" << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) 
{
    std::cout << "Bureaucrat Assignation" << std::endl;
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

void Bureaucrat::signForm(Form *f) const 
{
    try {
        f->beSigned(*this); 
        std::cout << name << " signed " << f->getName() << ".";
    } catch (std::exception &e) 
    {
        std::cout << name << " couldn’t sign " << f->getName() << " : not high-graded enough";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) 
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}