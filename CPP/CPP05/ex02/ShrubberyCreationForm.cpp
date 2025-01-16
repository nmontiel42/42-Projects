/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:38:32 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 16:07:52 by nekane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubbery", 145, 137, "DefaultShrubberyTarget")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getRequiredExecute(), other.getRequiredSign(), other.getTarget())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw(ShrubberyCreationForm::isNotSigned());
	else if (executor.getGrade() > this->getRequiredExecute())
        throw(ShrubberyCreationForm::GradeTooLowExcepcion());
    else
    {
        std::string filename = this->getTarget() + "_shrubbery";
        std::ofstream file(filename.c_str());
        if (!file)
        {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        file << "               ,@@@@@@@," << std::endl
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
            << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
            << "       |o|        | |         | |" << std::endl
            << "       |.|        | |         | |" << std::endl
            << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    }
}

