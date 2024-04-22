/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:04:43 by ygolshan          #+#    #+#             */
/*   Updated: 2024/02/16 08:54:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t) : AForm("ShrubberyCreationForm", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "SCF Destructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f) 
{
    if (this != &f) 
    {
        AForm::operator=(f);
        this->target = f.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    if (!getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > getToExec())
        throw AForm::GradeTooLowException();
    
    std::cout << executor.getName() << " execute " << this->getName() << " : ";
    try {
        std::ofstream out((target + "_shrubbery").c_str());
        if (!out)
            throw std::ios_base::failure("Error");

        out << "         *     *  \n";
        out << "      *    *     *    \n";
        out << "    *       *    *    \n";
        out << "      *   *  *      \n";
        out << "    *   * *     *   *\n";
        out << "   *  *  *    *     *  \n";
        out << "       *     *  *   *  \n";
        out << "      *    *    *    *  \n";
        out << "    *   *     *      *  \n";
        out << "      *     *    *   \n";
        out << "    *     *    *     *\n";
        out << "   *   *     *    *  \n";
        out << "      *    *  *  *   \n";
        out << "     *   *   *      *   \n";
        out << "    *  *  *      *    * \n";
        out << "  *  * *    * *  *    *  \n";
        out << "      *     *   *   *   \n";
        out << "    *    *      * *   *  \n";
        out << "  *    *    *  *     *   \n";
        out << "         |   |      \n";
        out << "         |   |      \n";
        out << "         |   |      \n";
        out << "    ______|___|______\n" << std::endl;

        out.close();
        std::cout << "shrubbery created in " << target << "_shrubbery" << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}