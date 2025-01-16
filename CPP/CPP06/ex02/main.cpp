/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:45:16 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 11:36:09 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() 
{
    srand(static_cast<unsigned int>(time(NULL)));

    int randomNumber = rand() % 3;

    switch (randomNumber)
    {
        case 0:
            std::cout << GREEN << "Created an object [A]" << std::endl;
            return new A();
        case 1:
            std::cout << GREEN << "Created an object [B]" << std::endl;
            return new B();
        case 2:
            std::cout << GREEN << "Created an object [C]" << std::endl;
            return new C();
        default:
            std::cout << RED << "Object is of unknown type, cant be created" << RESET << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
    if (A* a = dynamic_cast<A*>(p))
        std::cout << CYAN << "Object is of type A" << RESET << std::endl;
    else if (B* b = dynamic_cast<B*>(p))
        std::cout << CYAN << "Object is of type B" << RESET << std::endl;
    else if (C* c = dynamic_cast<C*>(p))
        std::cout << CYAN << "Object is of type C" << RESET << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << YELLOW << "Object is of type A" << RESET << std::endl;
        (void)a;
    }
    catch (const std::exception&)
    {
    }
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << YELLOW << "Object is of type B" << RESET << std::endl;
        (void)b;
    }
    catch (const std::exception&)
    {
    }

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << YELLOW << "Object is of type C" << RESET << std::endl;
        (void)c;
    }
    catch (const std::exception&)
    {
    }
}

int main()
{
    Base *random;

	random = generate();
	identify(random);
	identify(*random);

	delete random;
    
    return 0;   
}