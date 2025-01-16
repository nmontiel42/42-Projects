/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:52:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 12:32:57 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Includes.hpp"

Cure::Cure()
{	
	std::cout << "Default constructor for CURE wcalled" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure &other)
{
	std::cout << "Copy constructor for CURE called" << std::endl;
	this->type = other.getType();
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Operator assigment for CURE called" << std::endl;
	if (this != &other)
		this->type = other.getType();
	return *this;
}

Cure::~Cure()
{
	std::cout << "Destructor for CURE called" << std::endl;
}

Cure *Cure::clone() const
{
	Cure *cloned = new Cure(*this);
	return (cloned);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* Heals " << target.getName() << "\'s wounds *" << std::endl;
}