/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:54:02 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/23 12:04:25 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

bool onlyNumbers(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main()
{
    PhoneBook phonebook;
    while (true)
    {
        std::cout << BLUE << "       [MENU]:" << RESET << std::endl;
        std::cout << LIGHTCYAN << "1. " << RESET << "ADD" << std::endl;
        std::cout << LIGHTCYAN << "2. " << RESET << "SEACRH" << std::endl;
        std::cout << LIGHTCYAN << "3. " << RESET << "EXIT" << std::endl;

        std::string option;
        std::cout << "Select an opction: ";
        std::cin >> option;

        if (option == "exit")
            break;
        if (option == "1" || option == "ADD") {
            std::string name, lastName, nickName, secret, number;

            std::cout << "Name: ";
            std::getline(std::cin >> std::ws, name); 

            std::cout << "Last name: ";
            std::getline(std::cin >> std::ws, lastName);

            std::cout << "Nick name: ";
            std::getline(std::cin, nickName);

            std::cout << "Number: ";
            std::cin >> number;
            while (!onlyNumbers(number))
            {
                std::cout << RED << "Must be only numbers." << RESET << std::endl;
                std::cout << "Number: ";
                std::cin >> number;
            }
            std::cin.ignore();

            std::cout << "Dark Secret: ";
            std::getline(std::cin, secret);

            if (name.empty() || lastName.empty() || nickName.empty() || secret.empty() || number.empty())
            {
                std::cout << RED << "All fields are required. Please fill in all fields." << RESET << std::endl;
                continue;
            }
            Contact newContact(name, lastName, nickName, number, secret);
            phonebook.addContact(newContact);
        }
        else if (option == "2" || option == "SEACRH")
            phonebook.searchContacts();
            
        else if (option == "3" || option == "EXIT")
            break;
        else
            std::cout << RED << "Invalid option." << RESET << std::endl;
    }
    return (0);
}
