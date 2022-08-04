#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat{

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

    Bureaucrat();
    Bureaucrat(const std::string& _name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& b);
    
    const std::string& getName() const;
    int getGrade() const;
    void    setGrade(int grade);

    void    upGrade();
    void    downGrade();

private:
    const std::string _name;
    int _grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
