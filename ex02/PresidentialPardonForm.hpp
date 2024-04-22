/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:24 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/15 15:25:40 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
private:
    PresidentialPardonForm();
    std::string target;

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

	void execute(Bureaucrat const &executor) const;

};

#endif
