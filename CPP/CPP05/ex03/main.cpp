/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 22:34:01 by nekane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat good("Good", 5);
	Bureaucrat wrong("Wrong", 150);
	Intern interno1;
	AForm* scf = interno1.makeForm("ShrubberyCreationForm", "Shrubbery");
	AForm* rrf = interno1.makeForm("RobotomyRequestForm", "Robotmy");
	AForm* ppf = interno1.makeForm("PresidentialPardonForm", "Presidential");
	AForm* error = interno1.makeForm("ErrorForm", "Error");

	std::cout << YELLOW << "[SHRUBBERY CREATION]" << RESET << std::endl;

	wrong.signForm(*scf);
	wrong.executeForm(*scf);
	good.signForm(*scf);
	good.executeForm(*scf);
	wrong.executeForm(*scf);
	
	std::cout << YELLOW << "[ROBOTOMY REQUEST]" << RESET << std::endl;
	
	wrong.signForm(*rrf);
	wrong.executeForm(*rrf);
	good.signForm(*rrf);
	good.executeForm(*rrf);
	wrong.executeForm(*rrf);

	std::cout << YELLOW << "[PRESIDENTIAL PARDON]" << RESET << std::endl;

	wrong.signForm(*ppf);
	wrong.executeForm(*ppf);
	good.signForm(*ppf);
	good.executeForm(*ppf);
	wrong.executeForm(*ppf);

	delete scf;
	delete rrf;
	delete ppf;
	delete error;

	return 0;

}