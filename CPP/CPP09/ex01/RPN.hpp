/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:37:11 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 14:15:55 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class RPN
{
    private:
        std::stack<int> number;
    public:
    
        RPN();
        RPN(const std::string &);
        RPN(const RPN &);
        RPN& operator=(const RPN &);
        ~RPN();
        void calculator(char a);
};

#endif