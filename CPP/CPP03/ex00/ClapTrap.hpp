/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:55:54 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/30 15:06:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW   "\033[33m"
#define RESET   "\033[0m"


class ClapTrap
{
    private:
        std::string name;
        unsigned int hit;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap();
        ClapTrap(ClapTrap &);
        ClapTrap(const std::string &);
        ClapTrap &operator=(const ClapTrap &);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif