/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:10:30 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 15:24:23 by nekane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string name;
        bool _signed;
        const int requieredSign;
        const int requieredExecute;
        const std::string target;
    public:
        AForm();
        AForm(const std::string &, const int &, const int &, const std::string &);
        AForm(const AForm &);
        ~AForm();
        AForm& operator=(const AForm &);
        std::string getName() const;
        bool getSigned() const ;
        int getRequiredSign() const;
        int getRequiredExecute() const;
        std::string getTarget() const;
        void beSigned(Bureaucrat &);
        virtual void execute(Bureaucrat const &) const = 0;
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
        class isNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const AForm &);

#endif