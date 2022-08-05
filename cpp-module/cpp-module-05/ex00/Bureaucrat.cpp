#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (_grade > 150)
        throw GradeTooLowException("EXCEPTION: Grade too low");
    else if (_grade < 1)
        throw GradeTooHighException("EXCEPTION: Grade too high");
    std::cout << "Bureaucrat " << _name << "(" << _grade << ") constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) : _name(b._name)
{
    std::cout << "Bureaucrat " << _name << "(" << _grade << ") constructed. (copy constructor)" << std::endl;
    (*this) = b;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destructed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    _grade = b._grade;
    return (*this);
}

const std::string&  Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException("EXCEPTION: Grade too low");
    else if (grade < 1)
        throw GradeTooHighException("EXCEPTION: Grade too high");
    _grade = grade;
}


void    Bureaucrat::upGrade()
{
    setGrade(_grade - 1);
}

void    Bureaucrat::downGrade()
{
    setGrade(_grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char* m) : msg(m)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char* m) : msg(m)
{}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return msg;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return msg;
}

