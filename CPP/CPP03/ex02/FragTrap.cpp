/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:57:48 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 16:04:00 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hit = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    this->name = _name;
    this->hit = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTRap copy constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl; 
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << CYAN << "FragTrap " << this->name << " wants to high five!" << RESET << std::endl;
}
