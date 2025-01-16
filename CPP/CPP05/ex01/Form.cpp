/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:24:53 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 15:16:10 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default Form"), requieredSign(1), requieredExecute(1)
{
    //std::cout << "Default constructor for FORM called" << std::endl;
}

Form::Form(const std::string &oname, const int &orsign, const int &orexec) : name(oname), requieredSign(orsign), requieredExecute(orexec)
{
    //std::cout << "Custom constructor for FORM called" << std::endl;
    try
    {
        if (orsign > 150 || orexec > 150)
            throw(Form::GradeTooLowExcepcion());
        else if (orsign < 1 || orexec < 1)
            throw(Form::GradeTooHighExcepcion());
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

Form::Form(const Form &other) : name(other.name), requieredSign(other.requieredSign), requieredExecute(other.requieredExecute)
{
    //std::cout << "Copy constructor for FORM called" << std::endl;
    this->_signed = other._signed;
}

Form::~Form()
{
    //std::cout << "Destructor for FORM called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
   // std::cout << "Operator assigment for FORM called" << std::endl;
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

const char*  Form::GradeTooHighExcepcion::what() const throw()
{
    return ("{FORM} Grade too HIGH");
}

const char* Form::GradeTooLowExcepcion::what() const throw()
{
    return ("{FORM} Grade too LOW");
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getRequiredExecute() const
{
    return this->requieredExecute;
}

int Form::getRequiredSign() const
{
    return this->requieredSign;
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
    std::cout << other.getName() << ", with a required note to sign of " << other.getRequiredSign() << ", and a required note to execute of " << other.getRequiredExecute();
    if (other.getSigned())
        os << " is signed" << std::endl;
    else
        os << " is not signed" << std::endl;
    return os;
}

void Form::beSigned(Bureaucrat &other)
{
    try
    {
        if (other.getGrade() > this->getRequiredSign())
            throw(Form::GradeTooLowExcepcion());
        else
        {
            this->_signed = true;
            std::cout << other.getName() << " signed!" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
