/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:43:47 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/16 14:55:24 by nmontiel         ###   ########.fr       */
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
};
std::ostream &operator<<(std::ostream &, const Fixed &);

#endif