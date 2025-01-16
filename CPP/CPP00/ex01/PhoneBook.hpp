/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:14:08 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/23 12:04:31 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define LIGHTRED    "\033[91m"
#define LIGHTGREEN  "\033[92m"
#define LIGHTBLUE   "\033[94m"
#define LIGHTMAG    "\033[95m"
#define LIGHTCYAN   "\033[96m"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    int numContacts;

public:
    PhoneBook() : numContacts(0) {}

    void addContact(Contact& contact);
    void searchContacts();
};

#endif
