/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:33:39 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/05 15:02:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 10;
    Animal* animals[size];

    // Llenar la mitad del array con Dog y la otra mitad con Cat
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }

    // Llamar a makeSound para cada Animal
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    // Eliminar cada Animal y llamar a los destructores apropiados
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    return 0;
}