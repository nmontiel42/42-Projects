#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &);
        RobotomyRequestForm(const std::string);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const &) const;
};
