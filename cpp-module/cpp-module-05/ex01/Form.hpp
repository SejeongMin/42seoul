#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
public:
    class GradeTooHighException : public std::exception{
    public:
        GradeTooHighException(const char* msg);
        virtual const char* what() const throw();
    private:
        const char* msg;
    };

    class GradeTooLowException : public std::exception{
    public:
        GradeTooLowException(const char* msg);
        virtual const char* what() const throw();
    private:
        const char* msg;
    };

    Form();
    Form(const std::string& name, const int signGrade, const int executeGrade);
    Form(const Form& f);
    ~Form();
    Form& operator=(const Form& f);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void    beSigned(Bureaucrat& b);

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;

};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
