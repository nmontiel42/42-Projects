/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:45:36 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 16:57:41 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template<class T>
class Array
{
    private:
        T *things;
        unsigned int s;
    public:
        Array();
        Array(unsigned int n);
        Array(Array &);
        Array& operator=(Array &);
        T& operator[](unsigned int);
        ~Array();
        unsigned int size() const;
        class boundError : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif

