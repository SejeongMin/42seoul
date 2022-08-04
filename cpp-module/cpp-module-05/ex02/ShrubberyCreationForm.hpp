#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form{

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& f);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& f);

    void execute(Bureaucrat const & executor) const;

};

#endif
