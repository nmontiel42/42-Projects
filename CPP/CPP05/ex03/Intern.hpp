#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern &);
        Intern& operator=(Intern &);
        ~Intern();
        AForm *makeForm(const std::string, const std::string) const;
};
