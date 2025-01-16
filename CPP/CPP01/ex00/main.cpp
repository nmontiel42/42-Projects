/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:31:28 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/22 17:51:42 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << CYAN << "Creating zombie 1..." << RESET << std::endl;
	Zombie	zombie1("Bob");
	zombie1.announce();
	std::cout << CYAN << "Creating zombie 2..." << RESET << std::endl;
	Zombie*	zombie2 = newZombie("Alex");
	zombie2->announce();
	std::cout << CYAN << "Creating zombie 3..." << RESET << std::endl;
	randomChump("Alice");
	delete zombie2;
	return 0;
} 