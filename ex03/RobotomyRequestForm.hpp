/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:37 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 15:25:56 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
private:
    RobotomyRequestForm();
    std::string target;

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

	void execute(Bureaucrat const &executor) const;

};

#endif