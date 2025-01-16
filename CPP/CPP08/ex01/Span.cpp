/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:59:33 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:09:02 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(10)
{
}

Span::Span(const unsigned int number) : N(number)
{
}

Span::Span(const Span &other)
{
    this->N = other.N;
    this->total = other.total;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->total = other.total;
    }
    return *this;
}

int& Span::operator[](int index)
{
        return total[index];
}

Span::~Span()
{
}

const char* Span::noSpan::what() const throw()
{
    return ("There are not numbers/Only one number found");
}

const char* Span::newNumber::what() const throw()
{
    return ("Maximum number of numbers reached");
}

void Span::addNumber(unsigned int number)
{
    if (total.size() >= N)
        throw newNumber();
    total.push_back(number);
}

int Span::shortestSpan()
{
    if (total.size() < 2)
        throw noSpan();

    std::vector<int> sortedNumbers = total;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = std::numeric_limits<int>::max();
        
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (total.size() < 2)
        throw noSpan();

    int minNum = *std::min_element(total.begin(), total.end());
    int maxNum = *std::max_element(total.begin(), total.end());

    return maxNum - minNum;
}
