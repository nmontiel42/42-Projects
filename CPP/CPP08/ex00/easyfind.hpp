/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:30:20 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/20 17:43:58 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>

template<class T>
void easyfind(T& container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
        {
            std::cout << "Value " << value << " found in index " << std::distance(container.begin(), it) << std::endl;
            return;
        }
    }
    std::cout << "Value " << value << " not found" << std::endl;
}

#endif