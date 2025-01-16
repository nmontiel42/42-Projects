/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:43:20 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 14:17:50 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
    this->number = other.number;
}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->number = other.number;
    return *this;
}

RPN:: ~RPN()
{
}

RPN::RPN(const std::string &line)
{
    for (size_t i = 0; i < line.length(); i++)
    {
        if (std::isdigit(line[i]))
            this->number.push(atoi(&line[i]));
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
            this->calculator(line[i]);
        else if (isspace(line[i]) == 0)
        {
            std::cout << "Token not recognized: " << line[i] << std::endl;
            exit (1);
        }
    }
    std::cout << this->number.top() << std::endl;
}

void RPN::calculator(char op)
{
    if (this->number.size() <= 1)
    {
        std::cout << RED << "[ERROR] " << RESET << "Not enough numbers in stack" << std::endl;
        exit (1);
    }
    int a, b, res;
    b = this->number.top();
    this->number.pop();
    a = this->number.top();
    this->number.pop();
    switch (op)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            if (b == 0)
            {
                std::cout << RED << "[ERROR] " << RESET << "Division by zero" << std::endl;
                exit (1);
            }
            res = a / b;
            break;
        default:
            std::cout << RED << "[ERROR] " << RESET << "Invalid operation" << std::endl;
            break;
    }
    this->number.push(res);
}
