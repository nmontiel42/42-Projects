/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:11:40 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:15:14 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor for DOG called" << std::endl;
    this->type = "Dog";
}

Dog &Dog::operator=(Dog &other)
{
    std::cout << "Operator assigment for DOG called" << std::endl;
    if (this != &other)
        this->type = other.getType();
    return *this;
}

Dog::Dog(Dog &other)
{
    std::cout << "Copy constructor for DOG called" << std::endl;
    this->type = other.getType();
}

Dog::~Dog()
{
    std::cout << "Destructor for DOG called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << YELLOW << "WOF WOF" << RESET << std::endl;
}
