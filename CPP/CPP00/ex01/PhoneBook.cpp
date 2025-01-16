/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:14:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/23 12:04:11 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
void    PhoneBook::addContact(Contact& contact)
{
    if (numContacts < MAX_CONTACTS) {
        contacts[numContacts++] = contact;
        std::cout << GREEN << "Contact has been added!" << RESET << std::endl;
    } else {
        for (int i = 0; i < MAX_CONTACTS - 1; ++i)
            contacts[i] = contacts[i + 1];
        contacts[MAX_CONTACTS - 1] = contact;
        std::cout << YELLOW << "Phonebook is full. Oldest contact has been replaced." << RESET << std::endl;
    }
}

void    PhoneBook::searchContacts() {
    int option;
    if (numContacts == 0) {
        std::cout << RED << "There is no available contacts" << RESET << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::left << "Index" << " | ";
    std::cout << std::setw(10) << std::left << "Name" << " | ";
    std::cout << std::setw(10) << std::left << "Last name" << " | ";
    std::cout << std::setw(10) << std::left << "Nick name" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < numContacts; ++i) {
        std::string name = contacts[i].getName();
        std::string lastName = contacts[i].getLastName();
        std::string nickName = contacts[i].getNickName();
        if (name.length() >= 10) {
            name[9] = '.';
        }
        if (lastName.length() >= 10) {
            lastName[9] = '.';
        }
        if (nickName.length() >= 10) {
            nickName[9] = '.';
        }
        name.resize(10, ' ');
        lastName.resize(10, ' ');
        nickName.resize(10, ' ');
        std::cout << std::setw(10) << std::left << i + 1 << " | ";
        std::cout << std::left << name << " | ";
        std::cout << std::left << lastName << " | ";
        std::cout << std::left << nickName << " " << std::endl;
    }

    while (true)
    {
        std::cout << "Choose a contact to see more information: ";
        std::string input;
        std::cin >> input;
        bool isNumber = true;
        for (size_t i = 0; i < input.size(); ++i) {
            if (!isdigit(input[i])) {
                isNumber = false;
                break;
            }
        }       
        if (!isNumber) {
            std::cout << RED << "Invalid input. Please enter a number." << RESET << std::endl;
            continue;
        }
        option = atoi(input.c_str());
        if (option < 1 || option > numContacts)
            std::cout << RED << "Invalid contact number. Please choose a valid contact." << RESET << std::endl;
        else
            break;
    }
    
    Contact& selectedContact = contacts[option - 1];
    std::cout << YELLOW << "INFO ABOUT: " << RESET << selectedContact.getName() << std::endl;
    std::cout << YELLOW << "[" << RESET << "NAME" << YELLOW << "]" << RESET << ":" << selectedContact.getName() << std::endl;
    std::cout << YELLOW << "[" << RESET << "LAST NAME" << YELLOW << "]" << RESET << ":" << selectedContact.getLastName() << std::endl;
    std::cout << YELLOW << "[" << RESET << "NICK NAME" << YELLOW << "]" << RESET << ":"  << selectedContact.getNickName() << std::endl;
    std::cout << YELLOW << "[" << RESET << "PHONE NUMBER" << YELLOW << "]" << RESET << ":"  << selectedContact.getNumber() << std::endl;
    std::cout << YELLOW << "[" << RESET << "DARK SECRET" << YELLOW << "]" << RESET << ":"  <<  selectedContact.getSecret() << std::endl;
}
