/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:19:56 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 13:07:14 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &, const int );
        Bureaucrat(const Bureaucrat &);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &);
        std::string    getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        class GradeTooHighExcepcion : public std::exception
        {
            public:
                virtual const char *what () const throw();
        };
        class GradeTooLowExcepcion : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif