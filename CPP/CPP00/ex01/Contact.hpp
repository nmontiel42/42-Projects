/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <montielarce9@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:54:05 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/07 15:25:30 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>


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

class Contact {
private:
    std::string name;
    std::string lastName;
    std::string nickName;
    std::string number;
    std::string secret;
public:
    Contact() {}
    Contact(std::string& name, std::string& lastName, std::string& nickName, std::string& number, std::string& secret)
        : name(name), lastName(lastName), nickName(nickName), number(number), secret(secret) {}

    std::string getName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getNumber() const;
    std::string getSecret() const;
};

#endif