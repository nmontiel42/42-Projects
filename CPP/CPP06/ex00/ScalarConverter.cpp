/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:00:40 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/19 11:21:11 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//COF

ScalarConverter::ScalarConverter()
{
    std::cout << "Default conlituctor for SCALARCONVERTER called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    std::cout << "Copy conlituctor for SCALARCONVERTER called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor for SCALARCONVERTER called" << std::endl;
}

//UTILS

static int getCase(const std::string &lit)
{
    char* transform;
    
    if (lit == "nanf" || lit == "+inff" || lit == "-inff") 
        return PSEF;
    if (lit == "nan" || lit == "+inf" || lit == "-inf") 
        return PSED;
    if (lit.length() == 1 && ((lit[0] >= 32 && lit[0] < 48) || (lit[0] > 57 && lit[0] <= 126))) 
        return CHAR;
    
    strtol(lit.c_str(), &transform, 10); //Transforma una cadena de caracteres en un numero entero  
    
    if (*transform == '\0') 
        return INT;
    
    strtod(lit.c_str(), &transform); //Transforma una cadea de caracteres en un numero double
    
    if (*transform == 'f' || *transform == 'F')
        return FLT;
    if (*transform == '\0')
        return DBL;
    return INVALID;
}

static bool isRound(float number)
{
    return (number == static_cast<int>(number));
}

//CASES

static void charCase(const std::string &lit)
{
    char number;
    
    number = lit[0];
    std::cout << "Char: '" << number << "'" << std::endl;
    std::cout << "Int: " << static_cast<int>(number) << std::endl;
    std::cout << "Float: " << static_cast<float>(number) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(number) << ".0" << std::endl;
}

static void intCase(const std::string &lit)
{
    int number;
    
    number = std::atoi(lit.c_str());
    std::cout << "Char: ";
    if (std::isprint(static_cast<char>(number)))
        std::cout << "'" << static_cast<char>(number) << "'";
    else
        std::cout << YELLOW << "Non displayable" << RESET;
    std::cout << std::endl;
    std::cout << "Int: " << number << std::endl;
    std::cout << "Float: " << static_cast<float>(number) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(number) << ".0" << std::endl;
}

static void floatCase(const std::string &lit)
{
    float number;
    
    number = std::atof(lit.c_str());
    std::cout << "Char: ";
    if (isRound(number) && std::isprint(static_cast<char>(number)))
        std::cout << "'" << static_cast<char>(number) << "'";
    else
        std::cout << YELLOW << "Non displayable" << RESET;
    std::cout << std::endl;
    std::cout << "Int: " << static_cast<int>(number) << std::endl;
    std::cout << "Float: " << number << (isRound(number) ? ".0f" : "f") << std::endl;
    std::cout << "Double: " << static_cast<double>(number) << (isRound(number) ? ".0" : "") << std::endl; 
}

static void doubleCase(const std::string &lit)
{
    double number;
    
    number = std::atof(lit.c_str());
    std::cout << "Char: ";
    if (isRound(number) && std::isprint(static_cast<char>(number)))
        std::cout << "'" << static_cast<char>(number) << "'";
    else
        std::cout << YELLOW << "Non displayable" << RESET;
    std::cout << std::endl;
    std::cout << "Int: " << static_cast<int>(number) << std::endl;
    std::cout << "Float: " << static_cast<float>(number) << (isRound(number) ? ".0f" : "f") << std::endl;
    std::cout << "Double: " << number << (isRound(number) ? ".0" : "") << std::endl;
}

//MAIN FUNCTION

void ScalarConverter::convert(const std::string& lit)
{
    switch (getCase(lit))
    {
        case CHAR:
            charCase(lit);
            break;
        case INT:
            intCase(lit);
            break;
        case FLT:
            floatCase(lit);
            break;
        case DBL:
            doubleCase(lit);
            break;
        case PSEF:
            std::cout << "Char: " << RED << "impossible" << RESET << std::endl;
			std::cout << "Int: " << RED << "impossible" << RESET << std::endl;
			std::cout << "Float: " << lit << std::endl;
			std::cout << "Double: " << lit.substr(0, lit.length() - 1) << std::endl;
            break;
        case PSED:
            std::cout << "Char: " << RED << "impossible" << RESET << std::endl;
            std::cout << "Int: " << RED << "impossible" << RESET << std::endl;
            std::cout << "Float: " << lit << "f" << std::endl;
            std::cout << "Double: " << lit << std::endl;
            break;
        default:
            std::cout << RED << "Impossible conversion" << RESET << std::endl;
            break;
    }
}