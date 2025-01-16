/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:57:27 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/27 13:27:59 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedNumber;
		static const int fracBits = 8;
	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);
		Fixed &operator= (const Fixed &);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	toInt(void) const;

        //Comparison
        bool operator>(const Fixed &) const;
        bool operator<(const Fixed &) const;
        bool operator>=(const Fixed &) const;
        bool operator<=(const Fixed &) const;
        bool operator==(const Fixed &) const;
        bool operator!=(const Fixed &) const;

        //Arithmetic
        Fixed operator+(const Fixed &) const;
        Fixed operator-(const Fixed &) const;
        Fixed operator*(const Fixed &) const;
        Fixed operator/(const Fixed &) const;
        
        //Increment/Decrement
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        //Min and max
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};
std::ostream &operator<<(std::ostream &, const Fixed &);

#endif