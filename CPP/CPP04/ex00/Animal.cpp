/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:50:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:28:47 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor for ANIMAL called" << std::endl;
    this->type = "I dont know what i am";
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Copy constructor for ANIMAL called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Operator assignment for ANIMAL called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor for ANIMAL called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << YELLOW << "RAWR ?" << RESET << std::endl;
}

std::string    Animal::getType() const
{
    return (this->type);
}
