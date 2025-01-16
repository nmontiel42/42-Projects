/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:46 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/08 16:24:23 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string newName)
{
	name = newName;
}

void	HumanB::setWeapon(Weapon &weapn)
{
	weapon = &weapn;
}
