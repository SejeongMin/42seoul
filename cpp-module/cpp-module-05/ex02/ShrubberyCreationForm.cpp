#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137, "")
{
    std::cout << "ShrubberyCreationForm constructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "ShrubberyCreationForm constructed." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f) : Form(f)
{
	std::cout << "ShrubberyCreationForm constructed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f)
{
    Form::operator=(f);
	return *this;
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw Form::NotSignedException("EXCEPTION: The form is not signed yet.");
    else if (getExecuteGrade() < executor.getGrade())
        throw Form::GradeTooLowException("EXCEPTION: The executor's grade is too low to execute this form.");
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream file;
    file.open(filename.c_str(), 'w');
    if (file.is_open()){
        file << "tree";
        file.close();
    }
}
