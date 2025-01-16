/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:01:49 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:04:49 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "Includes.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &);
		~Ice();
		Ice &operator=(const Ice &);
		virtual Ice	*clone() const;
		virtual void use(ICharacter &target);
};

#endif