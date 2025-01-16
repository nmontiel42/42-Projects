#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm(const std::string);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const &) const;
};
