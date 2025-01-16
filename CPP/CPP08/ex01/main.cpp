/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:08:52 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:08:53 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

/* int main()
{
Span sp = Span(5);

sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
} */

int main()
{
    try 
    {
        Span sp(3);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);

        std::cout << CYAN << "[ELEMENTS]" << RESET << std::endl;

        std::cout << "Element at index 1: " << sp[0] << std::endl;
        std::cout << "Element at index 2: " << sp[1] << std::endl;
        std::cout << "Element at index 3: " << sp[2] << std::endl;

        std::cout << CYAN << "[SHORTEST AND LONGEST]" << RESET << std::endl;

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << CYAN << "[ERROR]" << RESET << std::endl;

        sp.addNumber(20);

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

/* int main()
{
    std::srand(std::time(0));

    const unsigned int numElements = 10000;

    try 
    {
        Span sp(numElements);

        for (unsigned int i = 0; i < numElements; ++i)
            sp.addNumber(std::rand() % 100000);

        std::cout << CYAN << "[VERIFY]" << RESET << std::endl;

        std::cout << "Element at index 0: " << sp[0] << std::endl;
        std::cout << "Element at index 1: " << sp[1] << std::endl;

        std::cout << CYAN << "[SHORTEST AND LONGEST]" << RESET << std::endl;

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
} */

