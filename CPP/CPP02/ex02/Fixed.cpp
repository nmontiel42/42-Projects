/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:57:51 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/27 14:17:46 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : fixedNumber(integer << fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum) : fixedNumber(static_cast<int>(roundf(floatNum * (1 << fracBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : fixedNumber(copy.fixedNumber)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &equal)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &equal)
	{
		this->fixedNumber = equal.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedNumber;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedNumber = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixedNumber) / (1 << fracBits);
}

int Fixed::toInt(void) const
{
	return this->fixedNumber >> fracBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

//Comparison

bool Fixed::operator>(const Fixed &other) const
{
    return (this->fixedNumber > other.fixedNumber);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->fixedNumber < other.fixedNumber);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->fixedNumber >= other.fixedNumber);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->fixedNumber <= other.fixedNumber);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixedNumber == other.fixedNumber);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixedNumber != other.fixedNumber);
}

//Arithmetic

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedNumber + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedNumber - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedNumber * other.getRawBits() >> fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedNumber / other.getRawBits());
	return (result);
}

//Increment/Decrement

Fixed	&Fixed::operator++()
{
	this->fixedNumber++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixedNumber++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->fixedNumber--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixedNumber--;
	return (temp);
}

//Min and max

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
