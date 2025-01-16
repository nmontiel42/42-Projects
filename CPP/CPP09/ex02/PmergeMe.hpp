/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:20:17 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/27 17:07:48 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <sys/time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class PmergeMe
{
    private:
        std::vector<int> vector;
        std::list<int> list;
        int len;
    public:
        PmergeMe();
        PmergeMe(char **);
        PmergeMe(PmergeMe &);
        PmergeMe& operator=(const PmergeMe &);
        ~PmergeMe();
        int getLen();
        void printList();
        void sortMergeList();
        void sortMergeVector();
};

#endif