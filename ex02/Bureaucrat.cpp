/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:03:48 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:08:56 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{
    std::cout << "Bureaucrat Void constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const n, int g) : name(n), grade(g) 
{
    std::cout << "Bureaucrat Full constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Hello, I'm " << name << " my grade is " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade) 
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    std::cout << "Hello, I'm " << name << " my grade is " << grade << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) 
{
    std::cout << "Bureaucrat Assignment operator called" << std::endl;
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
    std::cout << "Incrementing grade for " << name << std::endl;
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() 
{
    std::cout << "Decrementing grade for " << name << std::endl;
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm *f) const 
{
    try {
        f->beSigned(*this);
        std::cout << name << " signed " << f->getName() << "." << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn’t sign " << f->getName() << " : " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & f) const 
{
    try {
        f.execute(*this);
        std::cout << name << " executes " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << name << " couldn't execute " << f.getName() << " : " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b) 
{
    o << "Bureaucrat: " << b.getName() << ", Grade: " << b.getGrade();
    return o;
}