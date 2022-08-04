#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45, "")
{
    std::cout << "RobotomyRequestForm constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "RobotomyRequestForm constructed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : Form(f)
{
	std::cout << "RobotomyRequestForm constructed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& f)
{
    Form::operator=(f);
	return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw Form::NotSignedException("EXCEPTION: The form is not signed yet.");
    else if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException("EXCEPTION: The executor's grade is too low to execute this form.");
    std::cout << "**DRILLING NOISE**" << std::endl;
    srand((unsigned int)time(NULL));
    if (rand() % 2)
        std::cout << "Successed robotomy" << std::endl;
    else
        std::cout << "Failed robotomy" << std::endl;
}
