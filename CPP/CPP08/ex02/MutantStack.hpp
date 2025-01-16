/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:08:04 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:23:00 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class M>
class MutantStack : public std::stack<M>
{
    public:
        typedef typename std::stack<M>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack &);
        MutantStack& operator=(const MutantStack &);
        ~MutantStack();
        iterator begin()
        {
            return std::stack<M>::c.begin();
        }
        iterator end()
        {
            return std::stack<M>::c.end();
        }
};

#endif