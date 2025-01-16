/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:19:58 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/28 13:48:17 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float _x, const float _y);
        Point(const Point &other);
        Point &operator=(Point &other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point a, Point b, Point c, Point point);

#endif