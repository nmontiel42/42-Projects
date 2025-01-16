/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:38:32 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 22:38:24 by nekane           ###   ########.fr       */
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

        file << "   ┈╱╲┈┈┈╱╲┈┈┈╱╲┈┈" << std::endl
             << "   ╱╯╰╲┈┈╳╳┈┈╱╯╰╲┈" << std::endl
             << "   ╯╯╰╰╲╱╮╰╲╱╯╯╰╰╲" << std::endl
             << "   ╯╯╰╰╱╰╯╭╮╲╯╯╰╰╰" << std::endl
             << "   ╯╯╰╱╯╭╮╰╯╭╲╯╰╰╰" << std::endl
             << "   ▔▋╱╭╮╰╯╭╮╰╯╲▋▔▔" << std::endl
             << "   ┈╱╮╰╯╭╮╰╯╭╮╰╲┈┈" << std::endl
             << "   ┈▔▔▔▔▔▔▋▔▔▔▔▔┈┈" << std::endl;
    }
}

