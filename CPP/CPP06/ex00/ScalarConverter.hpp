/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:47:41 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 14:28:04 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCOMVERTER_HPP
# define SCALARCOMVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

enum literalType {
    CHAR,
    INT,
    FLT,
    DBL,
    PSEF,
    PSED,
    INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ScalarConverter& operator=(const ScalarConverter &);
    public:
        ~ScalarConverter();
        static void convert(const std::string &);
};

#endif