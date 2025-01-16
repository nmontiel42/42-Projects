/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:07:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:13:06 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Includes.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor for MATERIA SOURCE called" << std::endl;
	this->numLearned = 0;
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor for MATERIA SOURCE called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.learned[i] != NULL)
			this->learned[i] = other.learned[i]->clone();
		else
			this->learned[i] = NULL;
	}
	this->numLearned = other.numLearned;
}

MateriaSource &MateriaSource::operator= (const MateriaSource &other)
{
	if (this == &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.learned[i] != NULL)
				this->learned[i] = other.learned[i]->clone();
			else
				this->learned[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor for MATERIA SOURCE called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->learned[i] != NULL)
			delete (this->learned[i]);
	}
}

void MateriaSource::learnMateria(AMateria *newMateria)
{
	int i = 0;
	if (this->numLearned == 4)
		std::cout << "Materia source is full" << std::endl;
	else
	{
		while (i < 4)
		{
			if (this->learned[i] == NULL)
				break ;
			i++;
		}
		this->learned[i] = newMateria;
		this->numLearned++;
	}
	std::cout << "Learned " << this->learned[i]->getType() << " materia" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int i = 0;
	while (i < this->numLearned)
	{
		if (this->learned[i]->getType().compare(type) == 0)
		{
			std::cout << "Created " << this->learned[i]->getType() << " materia" << std::endl;
			return (this->learned[i]);	
		}
		i++;
	}
	std::cout << type << " is not a learned materia" << std::endl;
	return (NULL);
}
