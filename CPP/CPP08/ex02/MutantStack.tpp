/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:17:57 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:18:20 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<class M>
MutantStack<M>::MutantStack()
{
}

template<class M>
MutantStack<M>::MutantStack(const MutantStack &other)
{
    (void)other;
}

template<class M>
MutantStack<M> &MutantStack<M>::operator=(const MutantStack &other)
{
    (void)other;
    return *this;
}

template <class M>
MutantStack<M>::~MutantStack()
{
}

