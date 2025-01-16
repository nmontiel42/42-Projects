/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:27:06 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 12:39:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW   "\033[33m"
#define RESET   "\033[0m"

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &);
        WrongAnimal &operator=(const WrongAnimal &);
        ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
};

#endif