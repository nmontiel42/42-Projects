/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:35:16 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 13:35:38 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor for BRAIN called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor for BRAIN called" << std::endl;
    for (int i = 0;i <= 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Operator assigment for BRAIN called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i <= 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor for BRAIN called" << std::endl;
}
