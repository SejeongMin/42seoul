#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5, "")
{
    std::cout << "PresidentialPardonForm constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm constructed." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f) : Form(f)
{
	std::cout << "PresidentialPardonForm constructed." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& f)
{
    Form::operator=(f);
	return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw Form::NotSignedException("EXCEPTION: The form is not signed yet.");
    else if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException("EXCEPTION: The executor's grade is too low to execute this form.");
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
