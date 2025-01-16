/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:43:57 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 14:42:09 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
            std::string file(argv[1]);
        BitcoinExchange bt("data.csv", file);
        return 0;
    }
    return (std::cout << "Error: Usage: " << argv[0] << " <filename> " << std::endl, 1);
}