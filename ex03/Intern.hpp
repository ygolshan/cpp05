/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:05:36 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 15:29:08 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern 
{

private:
    AForm *forms[3];

public:
    Intern();
    Intern(Intern const &copy);
    ~Intern();

    Intern& operator=(Intern const &copy);

    AForm *makeForm(std::string name, std::string target);

	class FormNotCreated : public std::exception 
    {
	public:
		virtual const char* what() const throw() { return  "No form like this" ; }
	};
};

#endif