/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nekane <nekane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/12 16:13:50 by nekane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat good("Good", 5);
	Bureaucrat wrong("Wrong", 150);
	ShrubberyCreationForm prueba1("Shrubbery");
	RobotomyRequestForm prueba2("Robotomy");
	PresidentialPardonForm prueba3("Presidential");

	std::cout << YELLOW << "[BUREAUCRATS]" << RESET << std::endl;

	std::cout << good;
	std::cout << wrong;

	std::cout << YELLOW << "[FORMS]" << RESET << std::endl;

	std::cout << prueba1;
	std::cout << prueba2;
	std::cout << prueba3;

	std::cout << YELLOW << "[SHRUBBERY CREATION]" << RESET << std::endl;

	wrong.signForm(prueba1);
	wrong.executeForm(prueba1);
	good.signForm(prueba1);
	good.executeForm(prueba1);
	wrong.executeForm(prueba1);
	
	std::cout << YELLOW << "[ROBOTOMY REQUEST]" << RESET << std::endl;
	
	wrong.signForm(prueba2);
	wrong.executeForm(prueba2);
	good.signForm(prueba2);
	good.executeForm(prueba2);
	wrong.executeForm(prueba2);

	std::cout << YELLOW << "[PRESIDENTIAL PARDON]" << RESET << std::endl;

	wrong.signForm(prueba3);
	wrong.executeForm(prueba3);
	good.signForm(prueba3);
	good.executeForm(prueba3);
	wrong.executeForm(prueba3);

	return 0;

}