/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:10:48 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 14:18:17 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string ar1(argv[1]);
        if (ar1.empty()
        {
            std::cout << RED << "[ERROR]" << RESET << " Empty string\n";
            return 0;
        }
        RPN rpn(argv[1]);
        return 0;
    }
    std::cout << "Error: Usage: " << argv[0] << " <operation>" << std::endl;
    return 1;
}
