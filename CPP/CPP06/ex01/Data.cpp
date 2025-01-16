/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:08:20 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 15:35:18 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : string("Default string"), number(9)
{
    //std::cout << "Default constructor for DATA called" << std::endl;
}

Data::Data(const Data &other) : string(other.getString())
{
    //std::cout << "Copy constructor for DATA called" << std::endl;
}

Data::Data(const std::string other, int nother) : string(other), number(nother)
{
    //std::cout << "string constructor for DATA called" << std::endl;
}

Data& Data::operator=(const Data &other)
{
    if (this != &other)
    {
        this->string = other.getString();
        this->number = other.getNumber();
    }
    return *this;
}

Data::~Data()
{
    //std::cout << "Destructor for DATA called" << std::endl;
}

std::string Data::getString() const
{
    return this->string;
}

int Data::getNumber() const
{
    return this->number;
}

std::ostream &operator<<(std::ostream &os, Data &other)
{
    std::cout << other.getString() << ", " << other.getNumber();
    return os;
}
