/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:58:24 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 16:35:37 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<class T>

Array<T>::Array()
{
    std::cout << "Default constructor for ARRAY called" << std::endl;
    this->things = NULL;
    this->s = 0;
}

template<class T>
Array<T>::Array(unsigned int n)
{
    std::cout << "Unsigned int constructor for ARRAY called" << std::endl;
    this->things = new T[n];
    this->s = n;
}

template<class T>
Array<T>::Array(Array &other)
{
    std::cout << "Copy constructor for ARRAY called" << std::endl;
    this->things = new T[other.size()];
    this->s = other.size();
    for (unsigned int i = 0; i < this->s; i++)
        this->things[i] = other.things[i];
}

template<class T>
Array<T> &Array<T>::operator=(Array &other)
{
    if (this != &other)
    {
        if (this->things)
            delete[] this->things;
        this->things = new T(other.size());
        this->s = other.size();
        for (unsigned int i = 0; i < this->s; i++)
            this->things[i] = new T(other.things[i]);
    }
    return *this;
}

template<typename T>
T	&Array<T>::operator[](unsigned int nb)
{
	if (nb >= this->s)
		throw(Array<T>::boundError());
	else
		return (this->things[nb]);
}

template<class T>
Array<T>::~Array()
{
    std::cout << "Destructor for ARRAY called" << std::endl;
    delete[] this->things;
}

template<class T>
unsigned int Array<T>::size() const
{
    return this->s;       
}

template<class T>
const char* Array<T>::boundError::what() const throw()
{
    return ("ERROR, index is out of bounds!");
}

#endif