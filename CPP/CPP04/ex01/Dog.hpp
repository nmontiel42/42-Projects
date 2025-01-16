/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:02:34 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 13:27:01 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(Dog &);
        Dog &operator=(Dog &);
        ~Dog();
        void makeSound() const;
        
};

#endif