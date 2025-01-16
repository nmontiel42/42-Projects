/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:18:56 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 17:00:40 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main ()
{
    DiamondTrap diamond("Nekane");
    DiamondTrap diamond2(diamond);
    DiamondTrap diamond3("Nora");
    diamond = diamond3;

    diamond.attack("Enemy");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.guardGate();
    diamond2.whoAmI();

    return 0;
}