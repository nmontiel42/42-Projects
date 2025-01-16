/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:28:26 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 15:08:03 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->hit = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other) : name(other.name), hit(other.hit), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &_name) : name(_name), hit(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0)
    {
        std::cout << RED << "Claptrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << RESET << std::endl;
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

void    ClapTrap::takeDamage(unsigned int ammount)
{
    if (this->energyPoints <= 0)
    {
        std::cout << "No energy points left! " << this->name << " is tired!" << std::endl;
        return ;
    }
    if (this->hit <= 0)
    {
        std::cout << "No hit points left! " << this->name << " is dead!" << std::endl;
        return;
    }
    if (this->hit < ammount)
        this->hit = 0;
    else
        this->hit -= ammount;  
    std::cout << YELLOW << "Claptrap " << this->name << " has received " << ammount << " points of damage! Now it has " << this->hit <<" hit points left!" << RESET << std::endl;
    
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit <= 0)
    {
        std::cout << "No hit points left! " << this->name << " is dead!" << std::endl;
        return ;
    }
    if (this->energyPoints <= 0)
    {
        std::cout << "No energy points left! " << this->name << " is tired!" << std::endl;
        return;
    }
    this->hit += amount;
    this->energyPoints--;
    std::cout << YELLOW << "Claptrap " << this->name << " has repaired " << amount << " hit points! Now it has " << this->hit << " hit points!" << RESET << std::endl;
}

