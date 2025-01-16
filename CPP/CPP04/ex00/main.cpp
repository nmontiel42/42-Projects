/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:33:39 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 13:16:16 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* meta2 = new Dog();
    const Animal* meta3 = new Cat();
    const WrongAnimal* meta4 = new WrongAnimal();
    const WrongAnimal* meta5 = new WrongCat();
    
    std::cout << CYAN << meta->getType() << RESET << " " << std::endl;
    std::cout << CYAN << meta2->getType() << RESET << " " << std::endl;
    std::cout << CYAN << meta3->getType() << RESET << " " << std::endl;
    std::cout << CYAN << meta4->getType() << RESET << " " << std::endl;
    std::cout << CYAN << meta5->getType() << RESET << " " << std::endl;
    
    std::cout << "** WITH VIRTUAL **" << std::endl;

    meta->makeSound();
    meta2->makeSound();
    meta3->makeSound();

    std::cout << "** WITHOUT VIRTUAL **" << std::endl;

    meta4->makeSound();
    meta5->makeSound();
    
    delete meta;
    delete meta2;
    delete meta3;
    delete meta4;
    delete meta5;
    
    return 0;
}