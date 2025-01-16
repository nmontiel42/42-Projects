/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:05:52 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 15:05:55 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default contructor called" << std::endl;
    this->hit = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &_name) : ClapTrap(_name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    this->hit = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
   std::cout << "ScavTrap copy constructor called" << std::endl; 
   *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0)
    {
        std::cout << RED << "Scavtrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << RESET << std::endl;
        this->energyPoints--;
        return;
    }
    if (this->hit <= 0)
    {
        std::cout << "No hit points left! " << this->name << " is dead!" << std::endl;
        return;
    }
    std::cout << "No energy points left! " << this->name << " is tired!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << CYAN << "ScavTrap " << this->name << " is now on Gatekeeper mode" << RESET << std::endl;
}
