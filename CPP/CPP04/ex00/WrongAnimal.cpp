/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wronganimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:39:27 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:39:50 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default constructor for WRONG ANIMAL called" << std::endl;
    this->type = "I dont know what i am, but im wrong";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor for WRONG ANIMAL called" << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Operator assignment for WRONG ANIMAL called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor for WRONG ANIMAL called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << YELLOW << "? RWAR" << RESET << std::endl;
}
