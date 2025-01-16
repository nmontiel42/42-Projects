/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:51:16 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:04:28 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "Includes.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &);
		~Cure();
		Cure &operator=(const Cure &);
		virtual Cure *clone() const;
		virtual void use(ICharacter &);
};

#endif