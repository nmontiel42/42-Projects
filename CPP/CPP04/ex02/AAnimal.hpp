/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:26:01 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 15:12:42 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW   "\033[33m"
#define RESET   "\033[0m"

class AAnimal
{
    protected:
        std::string type; 
    public:
        AAnimal();
        AAnimal(const AAnimal &);
        AAnimal &operator=(const AAnimal &);
        virtual ~AAnimal();
        std::string getType() const;
        virtual void makeSound() const = 0; 
};

#endif