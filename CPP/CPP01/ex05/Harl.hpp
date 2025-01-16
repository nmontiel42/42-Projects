/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:20:53 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/08 17:42:55 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void	complain(std::string level);
};

#endif