/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:38:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/20 17:49:31 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

int main()
{
    std::vector<int> vec1;

    vec1.push_back(14);
    vec1.push_back(276);
    vec1.push_back(3);
    vec1.push_back(45);
    vec1.push_back(95);

    std::cout << CYAN << "[VECTORS]" << RESET << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout <<"Vector[" << i <<  "] = " << vec1[i] << std::endl;
    }
    
    std::cout << CYAN << "[EASYFIND]" << RESET << std::endl;
    int valueToFind = 14;
    easyfind(vec1, valueToFind);

    valueToFind = 45;
    easyfind(vec1, valueToFind);

    valueToFind = 2;
    easyfind(vec1, valueToFind);

    return 0;
}
