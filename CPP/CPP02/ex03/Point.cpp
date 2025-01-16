/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:20:53 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/28 13:46:20 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) 
{
    //std::cout << "Point created" << std::endl;
}

Point::Point(const float _x, const float _y) : x(_x), y(_y)
{
    //std::cout << "Float Constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(Point& other)
{
    return (other);
}

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}