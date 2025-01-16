#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern &other)
{
    (void)other;
}

Intern& Intern::operator=(Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string name, const std::string target) const
{
    std::string types[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;
    while(i < 3 && types[i] != name)
        i++;
    switch (i)
    {
    case (0):
        std::cout << CYAN << "An Intern created a Shrubbery Creation Form!" << RESET << std::endl;
        return (new ShrubberyCreationForm(target));
    case (1):
        std::cout << CYAN << "An Intern created a Robotomy Request Form!" << RESET << std::endl;
        return (new RobotomyRequestForm(target));
    case (2):
        std::cout << CYAN << "An Intern created a Presidential Pardon Form!" << RESET << std::endl;
        return (new PresidentialPardonForm(target));
    default :
        std::cout << CYAN << "An Intern tried to create a "  << RESET << name << CYAN << " form (he may be asleep)" << RESET << std::endl;
        return NULL;
    }
}