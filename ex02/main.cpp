/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:04 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/16 09:17:32 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    try {
        Bureaucrat yalda("yalda", 1);
        Bureaucrat ali("ali", 26);
        Bureaucrat mai("mai", 6);
        AForm* f1 = new PresidentialPardonForm("shahin");
        AForm* f2 = new RobotomyRequestForm("Bender");
        AForm* f3 = new ShrubberyCreationForm("feri");

        try {
            yalda.executeForm(*f1);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        std::cout << ali << std::endl;
        
        try {
            ali.signForm(f1);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        std::cout << *f1 << std::endl;
        
        try {
            ali.incrementGrade();
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        std::cout << ali << std::endl;
        
        try {
            ali.signForm(f1);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        std::cout << *f1 << std::endl;
        
        try {
            mai.executeForm(*f1);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        
        try {
            mai.incrementGrade();
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }
        
        try {
            mai.executeForm(*f1);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            mai.executeForm(*f2);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            ali.signForm(f2);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            mai.executeForm(*f2);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            mai.executeForm(*f3);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            ali.signForm(f3);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        try {
            mai.executeForm(*f3);
        } catch(std::exception &e) 
        {
            std::cout << e.what();
        }

        delete f1;
        delete f2;
        delete f3;
    } catch(std::exception &e) 
    {
        std::cout << e.what();
    }

    return 0;
}