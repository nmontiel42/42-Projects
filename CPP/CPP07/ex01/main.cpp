/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:19:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 15:37:40 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

int main()
{
    int array_i[] = {1, 2, 3, 4, 5};
    char array_c[] = {'h', 'o', 'l', 'a'};
    float array_f[] = {1.1, 2.2, 3.3, 4.4, 5.5};
   
    std::cout << CYAN << "[INT]" << RESET << std::endl;
    iter(array_i, 5, print<int>);
    std::cout << CYAN << "[CHAR]" << RESET << std::endl;
    iter(array_c, 4, print<char>);
    std::cout << CYAN << "[FLOAT]" << RESET << std::endl;
    iter(array_f, 4, print<float>);
        
    return 0;
}