/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:03:35 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 17:07:47 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name(""), toSign(0), toExec(0), isSigned(false) 
{
    std::cout << "AForm Void constructor called" << std::endl;
}

AForm::AForm(std::string &n, int &gts, int &gte) : name(n), toSign(gts), toExec(gte), isSigned(false) 
{
    std::cout << "AForm Full constructor called" << std::endl;
    if (toSign < 1 || toExec < 1) 
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150) 
        throw GradeTooLowException();
    std::cout << *this << std::endl;
}

AForm::AForm(std::string n, int gts, int gte) : name(n), toSign(gts), toExec(gte), isSigned(false) 
{
    std::cout << "AForm Full constructor called" << std::endl;
    if (toSign < 1 || toExec < 1) 
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150) 
        throw GradeTooHighException();
    std::cout << *this << std::endl;
}

AForm::AForm(AForm const &copy) : name(copy.name), toSign(copy.toSign), toExec(copy.toExec), isSigned(copy.isSigned) 
{
    std::cout << "AForm Copy constructor called" << std::endl;
    std::cout << *this << std::endl;
}

AForm::~AForm() { std::cout << "AForm destructor" << std::endl; }

AForm& AForm::operator=(const AForm &copy) 
{
    std::cout << "AForm Assignation" << std::endl;
    if (this != &copy) {
        isSigned = copy.isSigned;
    }
    return *this;
}

std::string AForm::getName() const { return name; }
int AForm::getToSign() const { return toSign; }
int AForm::getToExec() const { return toExec; }
bool AForm::getIsSigned() const { return isSigned; }
void AForm::setSigned(bool s) { isSigned = s; }

void AForm::beSigned(const Bureaucrat &b) 
{
    if (isSigned) {
        std::cout << "Form already signed" << std::endl;
        return ;
    }
    if (b.getGrade() > toSign) 
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &o, const AForm &f) 
{
    o << "Form: " << f.getName() << ", Grade required to sign: " << f.getToSign();
    o << ", Grade required to execute: " << f.getToExec() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
    return o;
}