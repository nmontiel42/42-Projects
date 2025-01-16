/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:44:18 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 17:06:03 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
# include <string>
# include <stdint.h>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

class Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &);
        Serializer& operator=(const Serializer &);
    public:
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif