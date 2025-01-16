/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:37:04 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/22 17:54:53 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"
#define CYAN    "\033[36m"


int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << CYAN << "[*]MEMORY ADRESSES[*]" << RESET << std::endl;
	std::cout << YELLOW << "str: " << RESET << &str << std::endl;
	std::cout << YELLOW << "stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << YELLOW << "stringREF: " << RESET << &stringREF << std::endl;

	std::cout << CYAN << "[*]VALUES[*]" << RESET << std::endl;
	std::cout << YELLOW << "str: " << RESET << str << std::endl;
	std::cout << YELLOW << "stringPTR: " << RESET << *stringPTR << std::endl;
	std::cout << YELLOW << "stringREF: " << RESET << stringREF << std::endl;

	return 0;
}