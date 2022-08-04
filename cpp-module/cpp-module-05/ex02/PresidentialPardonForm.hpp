#ifndef  PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form{

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& f);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& f);

    void execute(Bureaucrat const & executor) const;

};

#endif
