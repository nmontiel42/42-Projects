/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:45:15 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:04:13 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "Includes.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
			AMateria();
			AMateria(const AMateria &);
			AMateria(std::string const &type);
			virtual	~AMateria();
			AMateria &operator=(const AMateria &);
			std::string const	&getType() const;
			virtual AMateria	*clone() const = 0;
			virtual void		use(ICharacter &target);
};

#endif