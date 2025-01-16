/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:53 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 15:20:49 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default AForm"), _signed(false), requieredSign(1), requieredExecute(1), target("Default target")
{
    //std::cout << "Default constructor for AFORM called" << std::endl;
}

AForm::AForm(const std::string &oname, const int &orsign, const int &orexec, const std::string &otarget) : name(oname), _signed(false) ,requieredSign(orsign), requieredExecute(orexec), target(otarget)
{
    //std::cout << "Custom constructor for AFORM called" << std::endl;
    try
    {
        if (orsign > 150 || orexec > 150)
            throw(AForm::GradeTooLowExcepcion());
        else if (orsign < 1 || orexec < 1)
            throw(AForm::GradeTooHighExcepcion());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

AForm::AForm(const AForm &other) : name(other.name), _signed(other.getSigned()), requieredSign(other.requieredSign), requieredExecute(other.requieredExecute), target(other.target)
{
    //std::cout << "Copy constructor for AFORM called" << std::endl;
    this->_signed = other._signed;
}

AForm::~AForm()
{
    //std::cout << "Destructor for AFORM called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
   // std::cout << "Operator assigment for AFORM called" << std::endl;
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

const char*  AForm::GradeTooHighExcepcion::what() const throw()
{
    return ("{AFORM} Grade too HIGH");
}

const char* AForm::GradeTooLowExcepcion::what() const throw()
{
    return ("{AFORM} Grade too LOW");
}

const char* AForm::isNotSigned::what() const throw()
{
    return ("{AFORM} Is not signed");
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getRequiredExecute() const
{
    return this->requieredExecute;
}

int AForm::getRequiredSign() const
{
    return this->requieredSign;
}

std::string AForm::getTarget() const
{
    return this->target;
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
    std::cout << other.getName() << ", with a required note to sign of " << other.getRequiredSign() << ", and a required note to execute of " << other.getRequiredExecute();
    if (other.getSigned())
        os << " is signed" << std::endl;
    else
        os << " is not signed" << std::endl;
    return os;
}

void AForm::beSigned(Bureaucrat &other)
{
    try
    {
        if (other.getGrade() > this->getRequiredSign())
            throw(AForm::GradeTooLowExcepcion());
        else
        {
            this->_signed = true;
            std::cout << other.getName() << CYAN << " signed " << RESET <<  this->getName() << CYAN << " successfully!" <<  RESET << std::endl;

        }
    }
    catch(const std::exception& e)
    {
        std::cout << other.getName() << CYAN << " wasn't able to sign " << RESET << this->getName() << std::endl;
        std::cerr << e.what() << '\n';
    }
}
