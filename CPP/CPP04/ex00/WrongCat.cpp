/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:08:31 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 13:08:51 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "Default constructor for WRONG CAT called" << std::endl;
    this->type = "Wrong cat";
}

WrongCat::WrongCat(WrongCat &other)
{
    std::cout << "Copy cosntructor for WRONG CAT called" << std::endl;
    this->type = other.getType();
}

WrongCat& WrongCat::operator=(WrongCat &other)
{
    std::cout << "Copy assignment for WRONG CAT called" << std::endl;
    if (this != &other)
        this->type = other.getType();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor for WRONG CAT called" << std::endl; 
}

void    WrongCat::makeSound() const
{
    std::cout << YELLOW << "UAIM UAIM" << RESET << std::endl;
}
