#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form{

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& f);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& f);

    void execute(Bureaucrat const & executor) const;

};

#endif
