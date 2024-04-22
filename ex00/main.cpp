/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:03:10 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:02:48 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try {
        Bureaucrat b1("yalda", 15);
        Bureaucrat b("shahab", 2);
        Bureaucrat b2(b1);
        Bureaucrat b3("feri", 149);

        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;

        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;

        Bureaucrat b4("Minimum", -3);
    } catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Maximum", 666);
    } catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}