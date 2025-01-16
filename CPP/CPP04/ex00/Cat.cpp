/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:38:48 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:39:07 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor for CAT called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat &other)
{
    std::cout << "Copy constructor for CAT called" << std::endl;
    this->type = other.getType();
}

Cat& Cat::operator=(Cat &other)
{
    std::cout << "Operator assigment for CAT called" << std::endl;
    if (this != &other)
        this->type = other.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor for CAT called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "MIAU MIAU" << RESET << std::endl;
}
