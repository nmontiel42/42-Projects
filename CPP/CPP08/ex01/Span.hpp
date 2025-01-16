/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:52:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:09:07 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <limits>

class Span
{
    private:
        unsigned int N;
        std::vector<int> total;
    public:
        Span();
        Span(const unsigned int);
        Span(const Span &);
        Span& operator=(const Span &);
        int& operator[](int index);
        ~Span();
        void addNumber(unsigned int);
        int shortestSpan();
        int longestSpan();
        class noSpan : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class newNumber : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
