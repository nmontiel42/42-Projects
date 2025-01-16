/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:02:34 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:43:04 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW   "\033[33m"
#define RESET   "\033[0m"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog &);
        Dog &operator=(Dog &);
        ~Dog();
        void makeSound() const;
        
};

#endif