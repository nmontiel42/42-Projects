/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:31:14 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/15 18:38:56 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << CYAN << "[DEBUG]" << RESET << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << CYAN << "[INFO]" << RESET << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << CYAN << "[WARNING]" << RESET << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << CYAN << "[ERROR]" << RESET << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complaintFunction[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	bool levelFound = false;
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*complaintFunction[i])();
			levelFound = true;
			break;
		}
	}
	if (!levelFound)
		std::cout << CYAN << "[INVALID]" << RESET << std::endl << "Harl cant complain like that." << std::endl;
}
