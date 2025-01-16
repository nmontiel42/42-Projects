/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:45:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:39:30 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Includes.hpp"

Character::Character()
{
	std::cout << "Default constructor for CHARACTER called" << std::endl;
	this->name = "Default name";
	for (int i = 0; i < 3; i++)
		this->inventory[i] = NULL;
	this->materialEquiped = 0;
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor for CHARCATER called" << std::endl;
	this->name = other.getName();
	for (int i = 0; i < 3; i++)
		this->inventory[i] = other.inventory[i]->clone();
	this->materialEquiped = other.materialEquiped;
}

Character::Character(const std::string name)
{
	std::cout << "Name constructor for CHARACTER called" << std::endl;
	this->name = name;
	this->materialEquiped = 0;
	for (int i = 0; i < 3; i++)
		this->inventory[i] = NULL;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->name = other.getName();
		for (int i = 0; i < 3; i++)
		{
			if (this->inventory[i] != NULL)
				delete (this->inventory[i]);
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor for CHARACTER called" << std::endl;
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int i = 0;

	if (this->materialEquiped == 4)
	{
		std::cout << "The inventory is already full" << std::endl;
		this->noEquiped(m);
	}
	else
	{
		while (this->inventory[i] != NULL)
			i++;
		this->inventory[i] = m;
		this->materialEquiped++;
		std::cout << "Equiped a " << m->getType() << " type materia" << std::endl;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index" << std::endl;
	else if (this->inventory[idx] == NULL)
		std::cout << "Empty slot" << std::endl;
	else
	{
		this->noEquiped(this->inventory[idx]);
		this->inventory[idx] = NULL;
		this->materialEquiped--;
		std::cout << "Unequiped " << this->getName() << "\'s slot number " << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index" << std::endl;
	else if (this->inventory[idx] == NULL)
		std::cout << "Empty slot" << std::endl;
	else
		this->inventory[idx]->use(target);
}

int Character::unequipedSize = 0;
AMateria **Character::unequipedMaterias = NULL;

void	Character::noEquiped(AMateria *unequipped)
{
	this->unequipedSize++;
	AMateria **newMatrix = new AMateria *[this->unequipedSize];
	int i = 0;
	while (i < this->unequipedSize - 1)
	{
		newMatrix[i] = this->unequipedMaterias[i];
		i++;
	}
	newMatrix[i] = unequipped;
	if (this->unequipedMaterias != NULL)
		delete[] this->unequipedMaterias;
	this->unequipedMaterias = newMatrix;
}
