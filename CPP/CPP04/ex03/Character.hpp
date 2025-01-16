/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:02:00 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:22:53 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Includes.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*inventory[4];
		std::string	name;
		int			materialEquiped;
	public:
		Character();
		Character(const Character &);
		Character(const std::string);
		~Character();
		Character &operator=(const Character &);
		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
		void	noEquiped(AMateria *);
		static int unequipedSize;
		static AMateria **unequipedMaterias;
};

#endif