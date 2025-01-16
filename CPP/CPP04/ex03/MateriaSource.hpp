/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:07:31 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/06 11:12:55 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "Includes.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*learned[4];
		int			numLearned;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);
		~MateriaSource();
		MateriaSource &operator= (const MateriaSource &);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const &type);
};

#endif