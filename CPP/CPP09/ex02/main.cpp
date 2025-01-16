/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:36:30 by nmontiel          #+#    #+#             */
/*   Updated: 2024/07/01 12:23:03 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    struct timeval start, end;
    long listTimer, vectorTimer;
    if (argc > 1)
    {
        PmergeMe pm(++argv);
        std::cout << "Before: ";
        pm.printList();
        gettimeofday(&start, NULL);
        pm.sortMergeList();
        gettimeofday(&end, NULL);
        listTimer = end.tv_usec - start.tv_usec;
        gettimeofday(&start, NULL);
        pm.sortMergeVector();
        gettimeofday(&end, NULL);
        vectorTimer = end.tv_usec - start.tv_usec;
        std::cout << "After: ";
        pm.printList();
        std::cout << "Time to process a range of "<< pm.getLen() << " elements with std::list : " << listTimer << " us." << std::endl;
	    std::cout << "Time to process a range of "<< pm.getLen() << " elements with std::vector : " << vectorTimer << " us." << std::endl;
        return 0;
    }
    std::cout << "Error: Usage: " << argv[0] << " + <arguments>" << std::endl;
    return 1;
}