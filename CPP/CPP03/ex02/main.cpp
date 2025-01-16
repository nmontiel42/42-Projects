/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:18:56 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 16:08:29 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
    FragTrap tramp;
    FragTrap tramp1("Nekane");
    FragTrap tramp2(tramp1);
    FragTrap tramp3("Nora");
    tramp1 = tramp3;

    tramp1.highFivesGuys();
    tramp2.highFivesGuys();

    tramp1.attack("Nekane");
    tramp2.takeDamage(30);
    tramp1.attack("Nekane");
    tramp2.takeDamage(30);
    tramp2.beRepaired(15);
    tramp1.attack("Nekane");
    tramp1.attack("Nekane");
    tramp1.attack("Nekane");
    tramp2.takeDamage(90);
    tramp2.beRepaired(90);
        
    return 0;
}