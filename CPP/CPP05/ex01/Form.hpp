/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:10:30 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 14:33:48 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool _signed;
        const int requieredSign;
        const int requieredExecute;
    public:
        Form();
        Form(const std::string &, const int &, const int &);
        Form(const Form &);
        ~Form();
        Form& operator=(const Form &);
        std::string getName() const;
        bool getSigned() const ;
        int getRequiredSign() const;
        int getRequiredExecute() const;
        void beSigned(Bureaucrat &);
        class GradeTooHighExcepcion : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowExcepcion : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const Form &);

#endif