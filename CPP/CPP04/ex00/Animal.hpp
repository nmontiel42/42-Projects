/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:26:01 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:28:40 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW   "\033[33m"
#define RESET   "\033[0m"

class Animal
{
    protected:
        std::string type; 
    public:
        Animal();
        Animal(const Animal &);
        Animal &operator=(const Animal &);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const; 
};

#endif