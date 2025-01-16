/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:21:35 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/25 11:28:35 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"

int main() {
    {
        std::cout << CYAN << "[CON STD::LIST]" << RESET << std::endl;

        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::list<int> s(mlist);
    }
    {
        std::cout << CYAN << "[CON MUTANTSTACK]" << RESET << std::endl;

        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
        return 0;
    }
}