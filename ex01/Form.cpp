/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:02:13 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:19:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""), toSign(0), toExec(0), isSigned(false) 
{
    std::cout << "Form Void constructor called" << std::endl;
}

Form::Form(std::string &n, int &gts, int &gte) : name(n), toSign(gts), toExec(gte), isSigned(false) 
{
    std::cout << "Form Full constructor called" << std::endl;
    if (toSign < 1 || toExec < 1) 
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150) 
        throw GradeTooLowException();
    std::cout << *this << std::endl;
}

Form::Form(std::string n, int gts, int gte) : name(n), toSign(gts), toExec(gte), isSigned(false) 
{
    std::cout << "Form Full constructor called" << std::endl;
    if (toSign < 1 || toExec < 1) 
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150) 
        throw GradeTooLowException();
    std::cout << *this << std::endl;
}

Form::Form(Form const &copy) : name(copy.name), toSign(copy.toSign), toExec(copy.toExec), isSigned(copy.isSigned)
{
    std::cout << "Form Copy constructor called" << std::endl;
    std::cout << *this << std::endl;
}

Form::~Form() { std::cout << "Form destructor" << std::endl; }

Form& Form::operator=(const Form &copy) 
{
    std::cout << "Form Assignation" << std::endl;
    if (this != &copy) 
    {
        isSigned = copy.isSigned;
    }
    return *this;
}

std::string Form::getName() const { return name; }
int Form::getToSign() const { return toSign; }
int Form::getToExec() const { return toExec; }
bool Form::getIsSigned() const { return isSigned; }

void Form::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > toSign) 
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &o, const Form &f) 
{
    o << "Form: " << f.getName() << ", Grade required to sign: " << f.getToSign();
    o << ", Grade required to execute: " << f.getToExec() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
    return o;
}