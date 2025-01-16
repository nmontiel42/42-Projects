/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:50:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 15:15:48 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default constructor for AANIMAL called" << std::endl;
    this->type = "I dont know what i am";
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
    std::cout << "Copy constructor for AANIMAL called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    std::cout << "Operator assignment for AANIMAL called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor for AANIMAL called" << std::endl;
}

void    AAnimal::makeSound() const
{
    std::cout << YELLOW << "RAWR ?" << RESET << std::endl;
}

std::string    AAnimal::getType() const
{
    return (this->type);
}
