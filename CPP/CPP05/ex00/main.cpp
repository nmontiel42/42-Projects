/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 15:10:19 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat try1;
    Bureaucrat try2("Miau", 90);
    Bureaucrat try3("Tomate", 1);
    Bureaucrat try4("Azucar", 150);

    std::cout << try1;
    std::cout << try2;
    std::cout << try3;
    std::cout << try4;

    //No excepcions
    std::cout << CYAN << "[NO EXCEPCIONS]" << RESET << std::endl;
    try2.decrement();
    std::cout << try2;
    try2.increment();
    std::cout << try2;

    //Too high
    std::cout << CYAN << "[TOO HIGH EXCEPCION]" << RESET << std::endl;
    try3.increment();
    std::cout << try3;
    try3.decrement();
    std::cout << try3;

    //Too low
    std::cout << CYAN << "[TOO LOW EXCEPCION]" << RESET << std::endl;
    try4.decrement();
    std::cout << try4;
    try4.increment();
    std::cout << try4;

    return 0;
}