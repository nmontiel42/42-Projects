/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:09:54 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 17:09:10 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe &other)
{
    this->vector = other.vector;
    this->list = other.list;
    this->len = other.len;
}

PmergeMe::PmergeMe(char **argv)
{
    int len = 0, value;

    while (argv[len])
    {
        value = atoi(argv[len]);
        if (std::find(this->list.begin(), this->list.end(), value) == this->list.end() && value >= 0)
        {
            this->vector.push_back(value);
            this->list.push_back(value);
        }
        len++;
    }
    this->len = len;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->vector = other.vector;
        this->list = other.list;
        this->len = other.len;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printList()
{
    std::list<int>::iterator it = this->list.begin();
    for (;it != this->list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static void recursiveSortMerge(std::list<int>::iterator begin, std::list<int>::iterator end)
{

    std::list<int>::iterator originalList;
    std::list<int>::iterator itBeginVector;
    std::list<int>::iterator itEndVector;

    if (std::distance(begin, end) > 1)
    {
        std::list<int>::iterator medium;
        medium = begin;
        std::advance(medium, std::distance(begin ,end) / 2);
        recursiveSortMerge(begin, medium);
        recursiveSortMerge(medium, end);
        
        std::list<int> beginVector(begin, medium);
        std::list<int> endVector(medium, end);
        originalList = begin;
        itBeginVector = beginVector.begin();
        itEndVector = endVector.begin();
        while (itBeginVector != beginVector.end() && itEndVector != endVector.end())
        {
            if (*itBeginVector <= *itEndVector)
            {
                *originalList = *itBeginVector;
                itBeginVector++;
            }
            else
            {
                *originalList = *itEndVector;
                itEndVector++;
            }
            originalList++;
        }
        while (itBeginVector != beginVector.end())
        {
            *originalList = *itBeginVector;
            originalList++;
            itBeginVector++;
        }
        while (itEndVector != endVector.end())
        {
            *originalList = *itEndVector;
            originalList++;
            itEndVector++;
        }
    }
}

void PmergeMe::sortMergeList()
{
    recursiveSortMerge(this->list.begin(), this->list.end());
}

static void recursiveSortMergeVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{

    std::vector<int>::iterator originalList;
    std::vector<int>::iterator itBeginVector;
    std::vector<int>::iterator itEndVector;

    if (std::distance(begin, end) > 1)
    {
        std::vector<int>::iterator medium;
        medium = begin;
        std::advance(medium, std::distance(begin ,end) / 2);
        recursiveSortMergeVector(begin, medium);
        recursiveSortMergeVector(medium, end);
        
        std::vector<int> beginVector(begin, medium);
        std::vector<int> endVector(medium, end);
        originalList = begin;
        itBeginVector = beginVector.begin();
        itEndVector = endVector.begin();
        while (itBeginVector != beginVector.end() && itEndVector != endVector.end())
        {
            if (*itBeginVector <= *itEndVector)
            {
                *originalList = *itBeginVector;
                itBeginVector++;
            }
            else
            {
                *originalList = *itEndVector;
                itEndVector++;
            }
            originalList++;
        }
        while (itBeginVector != beginVector.end())
        {
            *originalList = *itBeginVector;
            originalList++;
            itBeginVector++;
        }
        while (itEndVector != endVector.end())
        {
            *originalList = *itEndVector;
            originalList++;
            itEndVector++;
        }
    }
}

void PmergeMe::sortMergeVector()
{
    recursiveSortMergeVector(this->vector.begin(), this->vector.end());
}

int PmergeMe::getLen()
{
    return (this->len);
}