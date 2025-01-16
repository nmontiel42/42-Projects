/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:01:54 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 12:32:51 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Includes.hpp"

Ice::Ice()
{
	std::cout << "Default constructor for ICE called" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice &other)
{
	std::cout << "Copy constructor for ICE called" << std::endl;
	this->type = other.getType();
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Operator assigment for ICE called" << std::endl;
	if (this != &other)
		this->type = other.getType();
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor for ICE called" << std::endl;
}

Ice *Ice::clone() const
{
	Ice *cloned = new Ice(*this);
	return (cloned);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* Shoots an ice bolt at " << target.getName() << " *" << std::endl;
}