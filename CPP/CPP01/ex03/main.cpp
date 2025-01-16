/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:16:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/22 17:55:18 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA humanA("Rose", club);
		humanA.attack();
		club.setType("some other type of club");
		humanA.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB humanB("Leo");
		humanB.setWeapon(club);
		humanB.attack();
		club.setType("some other type of club");
		humanB.attack();
	}
	return (0);
}