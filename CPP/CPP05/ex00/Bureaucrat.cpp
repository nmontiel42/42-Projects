/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:53:29 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 15:15:54 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(75)
{
    //std::cout << "Default constructor for BUREAUCRAT called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &other, const int otherg) : name(other)
{
    //std::cout << "Custom constructor for BUREAUCRAT called" << std::endl;
    try
    {
        if (otherg > 150)
            throw Bureaucrat::GradeTooLowExcepcion();
        else if (otherg < 1)
            throw Bureaucrat::GradeTooHighExcepcion();
        else
            this->grade = otherg;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        this->grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    //std::cout << "Copy constructor for BUREAUCRAT called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    //std::cout << "Operator assigment for BUREAUCRAT called" << std::endl;
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    //std::cout << "Destructor for BUREAUCRAT called"<< std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

const char*    Bureaucrat::GradeTooHighExcepcion::what() const throw()
{
    return ("{BUREAUCRAT} Grade too HIGH");
}

const char*    Bureaucrat::GradeTooLowExcepcion::what() const throw()
{
    return ("{BUREAUCRAT} Grade too LOW");
}

void Bureaucrat::decrement()
{
    try
    {
        if (Bureaucrat::getGrade() >= 150)
            throw Bureaucrat::GradeTooLowExcepcion();
        else
            this->grade++;
    }
    catch(std::exception &l)
    {
        std::cout << l.what() << std::endl;
        this->grade = 150;
    }
    
}

void Bureaucrat::increment()
{
    try
    {
        if (Bureaucrat::getGrade() <= 1)
            throw Bureaucrat::GradeTooHighExcepcion();
        else
            this->grade--;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        this->grade = 1;
    }
    
}

std::ostream	&operator<<(std::ostream &outs, const Bureaucrat &other)
{
	outs << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (outs);
}
