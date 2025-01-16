/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:33:39 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 15:16:33 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //const Animal* meta = new Animal();
    const AAnimal* meta2 = new Dog();
    const AAnimal* meta3 = new Cat();
    
    std::cout << CYAN << meta2->getType() << RESET << " " << std::endl;
    std::cout << CYAN << meta3->getType() << RESET << " " << std::endl;
    
    meta2->makeSound();
    meta3->makeSound();

    delete meta2;
    delete meta3;
    
    return 0;
}