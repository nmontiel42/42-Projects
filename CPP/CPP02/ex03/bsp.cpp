/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:20:37 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/28 14:14:35 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point a, Point b, Point c, Point point)
{
    Fixed areaABC = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
    
    Fixed areaABP = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (point.getX() - a.getX()) * (b.getY() - a.getY());
    
    Fixed areaBCP = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (point.getX() - b.getX()) * (c.getY() - b.getY());

    Fixed areaCAP = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (point.getX() - c.getX()) * (a.getY() - c.getY());

    bool insideTriangle = areaABC >= 0 && areaABP >= 0 && areaBCP >= 0 && areaCAP >= 0;
    
    return insideTriangle;
}