#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultRobotomy", 72, 45, "DefaultRobotomyTarget")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getRequiredExecute(), other.getRequiredSign(), other.getTarget())
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_signed = other.getSigned();
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getRequiredExecute())
        throw(RobotomyRequestForm::GradeTooLowExcepcion());
    else if (!this->getSigned())
        throw(RobotomyRequestForm::isNotSigned());
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << CYAN <<" has been robotomized successfully!" << RESET <<std::endl;
    else
        std::cout << this->getTarget() << CYAN << "'s robotomy failed!" << RESET << std::endl;
}
