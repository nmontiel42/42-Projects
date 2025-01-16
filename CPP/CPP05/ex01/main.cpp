/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:54:59 by nmontiel          #+#    #+#             */
/*   Updated: 2024/06/11 15:17:41 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1("Nekane", 75);
	Bureaucrat b2("Paula", 1);
	Bureaucrat b3("Antonio", 155);
	
	std::cout << CYAN << "[BUREAUCRATS]" << RESET << std::endl;
	std::cout << b1;
	std::cout << b2;
	std::cout << b3;

	Form f1("f1", 75, 75);
	Form f2("f2", 1, 1);
	Form f3("f3", 155, 155);

	std::cout << CYAN << "[FORMS]" << RESET << std::endl;
	std::cout << f1;
	std::cout << f2;
	std::cout << f3;

	b1.signForm(f1);
	b1.signForm(f2);
	b1.signForm(f3);

	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);

	b3.signForm(f1);
	b3.signForm(f2);
	b3.signForm(f3);

	return 0;
}