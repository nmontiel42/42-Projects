/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:07:56 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 15:32:04 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class A, class F>
void iter(A address, int length, F function)
{
    for(int i = 0; i < length; i++)
    {
        function(address[i]);
    }
    std::cout << "\n";
}

template <class A>
void print(A a)
{
    std::cout << a;
}
