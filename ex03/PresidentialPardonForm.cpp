/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:18 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/16 09:14:15 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string t) : AForm("PresidentialPardonForm", 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PPF Destructed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &f) 
{
    if (this != &f) 
    {
        AForm::operator=(f);
        this->target = f.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned()) 
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec()) 
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " execute " << this->getName() << " : " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}