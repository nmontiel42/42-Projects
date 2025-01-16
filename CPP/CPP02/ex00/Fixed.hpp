/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:58:52 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/14 17:20:50 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedNumber;
		static const int fracBits = 8;
	public:
		Fixed(void);
		Fixed(Fixed &);
		Fixed &operator= (const Fixed &);
		~Fixed(void);
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
};

#endif