/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:48 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 15:50:55 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *try1 = new Data("Nekane", 19);

    uintptr_t serialized = Serializer::serialize(try1);

    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << YELLOW << "Original Data: " << RESET << *try1 << std::endl;
    std::cout << YELLOW << "Serialized value: " << RESET << serialized << std::endl;
    std::cout << YELLOW << "Deserialized Data: " << RESET << *deserialized << std::endl;

    return 0;
}