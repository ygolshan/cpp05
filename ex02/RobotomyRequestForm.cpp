/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:30 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/16 09:21:08 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RRF Destructed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &f) 
{
    if (this != &f) 
    {
        AForm::operator=(f);
        this->target = f.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec())
        throw AForm::GradeTooLowException();

    std::cout << executor.getName() << " executes " << this->getName() << ": *Mechanical noises* ";
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed and " << this->target << " is safe" << std::endl;
}