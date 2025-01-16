/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:45:09 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:15:01 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Includes.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor for AMATERIA called" << std::endl;
	this->type = "Undefined type";
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "Copy constructor for AMATERIA called" << std::endl;
	this->type = other.type;
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "Type constructor for AMATERIA called" << std::endl;
	this->type = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->type = other.getType();
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor for AMATERIA called" << std::endl;
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* Undefined attack to " << target.getName() << " *" << std::endl;
}