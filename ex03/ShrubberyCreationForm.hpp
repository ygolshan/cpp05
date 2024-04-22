/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:49 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 15:26:13 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>
# include <string>

class ShrubberyCreationForm : public AForm 
{
private:
    ShrubberyCreationForm();
    std::string target;

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

	void execute(Bureaucrat const &executor) const;

};

#endif
