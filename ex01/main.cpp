/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:02:32 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 16:56:44 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
	try {
		Bureaucrat	b1("Ali", 9);
		Form		f1("Form 1", 8, 8);
		std::cout << b1 << std::endl;
		b1.signForm(&f1);
		std::cout << f1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.signForm(&f1);
		std::cout << f1 << std::endl;
	} catch (std::exception const &e) 
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}