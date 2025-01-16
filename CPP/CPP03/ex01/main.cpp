/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:18:56 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:28 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main ()
{
    ScavTrap tramp;
    ScavTrap tramp1("Nekane");
    ScavTrap tramp2(tramp1);
    ScavTrap tramp3("Nora");
    tramp1 = tramp3;

    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    tramp1.attack("Alex");
    

    tramp1.takeDamage(9);
    tramp1.beRepaired(8);

    tramp1.takeDamage(8);
    tramp1.beRepaired(10);

    tramp1.guardGate();
    
    return 0;
}