#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade, std::string target) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade), _target(target)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException("GradeTooHighException");
    else if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException("GradeTooLowException");
    std::cout << "Form " << _name << " constructed." << std::endl;
}

Form::Form(const Form& f) : _name(f._name), _signGrade(f._signGrade), _executeGrade(f._executeGrade)
{
    std::cout << "Form " << _name << " constructed.(copy constructor)" << std::endl;
    *this = f;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destructed." << std::endl;
}

Form& Form::operator=(const Form &f)
{
    _isSigned = f._isSigned;
    return *this;
}

const std::string&  Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

const std::string& Form::getTarget() const
{
    return _target;
}

Form::GradeTooHighException::GradeTooHighException(const char* m) : msg(m)
{}

Form::GradeTooLowException::GradeTooLowException(const char* m) : msg(m)
{}

Form::NotSignedException::NotSignedException(const char* m) : msg(m)
{}

const char* Form::GradeTooHighException::what() const throw()
{
    return msg;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return msg;
}

const char* Form::NotSignedException::what() const throw()
{
    return msg;
}

void    Form::beSigned(Bureaucrat& b)
{
    if (_signGrade < b.getGrade())
        throw GradeTooLowException("grade is too low");
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", form signed: " << f.getIsSigned() 
        << ", form target: " << f.getTarget()
        << ", form sign grade: " << f.getSignGrade()
        << ", form execute grade: " << f.getExecuteGrade() << std::endl;
    return os;
}
