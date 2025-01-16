#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("DefaultPresidential", 25, 5, "DefaultPresidentialTarget")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getRequiredSign(), other.getRequiredExecute(), other.getTarget())
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        this->_signed = other.getSigned();
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw(PresidentialPardonForm::isNotSigned());
    if (executor.getGrade() > this->getRequiredExecute())
        throw(PresidentialPardonForm::GradeTooLowExcepcion());
    std::cout << this->getTarget() << CYAN << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
