/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:56:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/22 17:54:16 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* horde1 = zombieHorde(10, "Paula");
	std::cout << YELLOW <<  "A horde of zombies named the same are going to announce themselves" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << CYAN << "Zombie number " << i << RESET << std::endl;
		horde1[i].announce();
	}
	delete[] horde1;
	return 0;
}