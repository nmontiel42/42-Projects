/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:10:12 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 16:57:29 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

int main()
{
    Array<std::string> array_s(4);
   

    std::cout << CYAN << "[STRING]" << RESET << std::endl;
    try
    {
        array_s[0] = "Hola";
        array_s[1] = "me";
        array_s[2] = "llamo";
        array_s[3] = "Nekane";
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Contenido de " << "[" << i << "]:" << array_s[i] << std::endl;
        }
            
	    std::cout << "El tamaño del Array es: " << array_s.size() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    {
        Array<int> array_i(4);
        
        std::cout << CYAN << "[INT]" << RESET << std::endl;
        try
        {
            array_i[0] = 1;
            array_i[1] = 2;
            array_i[2] = 3;
            array_i[3] = 4;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "Contenido de " << "[" << i << "]:" << array_i[i] << std::endl;
            }
            
	        std::cout << "El tamaño del Array es: " << array_i.size() << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Array<int> array_e(3);
        
        std::cout << CYAN << "[ERROR]" << RESET << std::endl;
        try
        {
            array_e[0] = 1;
            array_e[1] = 2;
            array_e[2] = 3;
            array_e[3] = 4;
            for (int i = 0; i < 3; i++)
            {
                std::cout << "Contenido de " << "[" << i << "]:" << array_e[i] << std::endl;
            }
            
	        std::cout << "El tamaño del Array es: " << array_e.size() << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

/* #define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */