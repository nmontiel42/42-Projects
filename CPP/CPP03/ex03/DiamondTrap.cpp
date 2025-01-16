/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:44:05 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 16:52:05 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    std::cout << "Diamond trap default constructor called" << std::endl;
    this->hit = FragTrap::hit;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << "Diamond trap name constructor called" << std::endl;
    this->name = name;
    this->hit = FragTrap::hit;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
{
    std::cout << "Diamond trap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond trap destructor called" << std::endl;
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}
