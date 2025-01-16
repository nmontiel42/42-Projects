/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:59:51 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/18 15:46:41 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
# include <string>
# include <stdint.h>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW   "\033[33m"

class Data
{
    private:
        std::string string;
        int number;
    public:
        Data();
        Data(const Data &);
        Data(std::string, int);
        Data& operator=(const Data &);
        ~Data();
        std::string getString() const;    
        int getNumber() const;
};
std::ostream &operator<<(std::ostream &os, Data &other);

#endif