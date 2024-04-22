/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:05:43 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/16 09:15:44 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    try {
        Bureaucrat ali("ali", 26);
        Bureaucrat mai("mai", 6);
        Intern someRandomIntern;
        AForm* rrf = nullptr;

        try {
            rrf = someRandomIntern.makeForm("A request", "shahin");
        } catch(std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }

        try {
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        } catch(std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }

        if (rrf) {
            try {
                mai.executeForm(*rrf);
            } catch(std::exception &e) 
            {
                std::cout << e.what() << std::endl;
            }

            try {
                ali.signForm(rrf);
            } catch(std::exception &e) 
            {
                std::cout << e.what() << std::endl;
            }

            try {
                mai.executeForm(*rrf);
            } catch(std::exception &e) 
            {
                std::cout << e.what() << std::endl;
            }

            delete rrf;
        }
    } catch(std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}