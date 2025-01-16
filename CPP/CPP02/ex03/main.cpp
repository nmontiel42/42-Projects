/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:29:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/28 16:03:54 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


int main()
{

    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);

    Point point(2, 1);

    bool insideTriangle = bsp(a, b, c, point);

    if (insideTriangle)
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
    return 0;
}