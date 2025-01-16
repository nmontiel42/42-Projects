/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:11:47 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 15:04:21 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class W>
void swap(W &a, W &b)
{
    W swap;

    swap = a;
    a = b;
    b = swap;
}

template <class W>
W  min(W &a, W&b)
{
    if (a == b)
        return b;
    else if (a > b)
        return b;
    else 
        return a;
}

template <class W>
W max(W &a, W&b)
{
    if (a == b)
        return b;
    else if (a > b)
        return a;
    else
        return b;
}


#endif