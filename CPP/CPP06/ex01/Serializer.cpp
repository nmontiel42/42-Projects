/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:03 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 15:39:18 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor for SERIALIZER called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    (void)other;
    std::cout << "Copy constructor for SERIALIZER called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Destructor for SERIALIZER called" << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}