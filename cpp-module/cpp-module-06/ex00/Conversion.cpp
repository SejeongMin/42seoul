#include "Conversion.hpp"
#include <sstream>

Conversion::Conversion() : _value(""), _type(0)
{}

Conversion::Conversion(const std::string& value) : _value(value), _type(0)
{
    checkType();
}

Conversion::Conversion(const Conversion& c)
{
    *this =  c;
}

Conversion::~Conversion()
{}

Conversion& Conversion::operator=(const Conversion& c)
{
    _value = c._value;
    _type = c._type;
    return *this;
}

const char* Conversion::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}

const char* Conversion::ImpossibleException::what() const throw()
{
    return "impossible";
}

void    Conversion::checkType()
{
    if (!_value.compare("nan") || !_value.compare("nanf") || !_value.compare("inf")
        || !_value.compare("+inf") || !_value.compare("-inf") || !_value.compare("+inff")
        || !_value.compare("-inff"))
    {
        _type = 1;
        return;
    }
    char* ptr = &_value[0];
    if (*ptr == '+' || *ptr == '-')
    {
        ptr++;
        if (*ptr == '.' || *ptr == 'f')
        {
            _type = 0;
            return;
        }
    }
    for (; *ptr; ptr++){
        if (!((*ptr >= '0' && *ptr <= '9')
            || (*ptr == '.' && (*(ptr + 1) >= '0' && *(ptr + 1) <= '9'))
            || (*ptr == 'f' && *(ptr + 1) == '\0')))
        {
            _type = 0;
            return;
        }
        if (*ptr == '.')
            _type = 2;
    }
    if (_type != 2)
        _type = 3;
}

void    Conversion::toChar()
{
    int i;
	try{
        std::cout << "char: ";
        if (!_type)
            throw ImpossibleException();
        try{
            i = std::stoi(_value);
            if (_type != 2 && _type != 3)
                throw ImpossibleException();
        } catch (std::exception & e){
            throw ImpossibleException();
        }
        try{
            if (i < 32 || i > 127)
                throw NonDisplayableException();
            std::cout << "\'" << static_cast<char>(i) << "\'" << std::endl;
        } catch (std::exception & e){
            std::cout << e.what() << std::endl;
        }
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}

void    Conversion::toInt()
{
    try{
        std::cout << "int: ";
        if (!_type)
            throw ImpossibleException();
        try{
            int i = std::stoi(_value);
            if (_type != 2 && _type != 3)
                throw ImpossibleException();
            std::cout << static_cast<int>(i) << std::endl;
        } catch (std::exception & e){
            throw ImpossibleException();
        }
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}

void    Conversion::toDouble()
{
    double d = 0.0;
    try{
        std::cout << "double: ";
        if (!_type)
            throw ImpossibleException();
        try{
            d = std::stod(_value);
        } catch (std::exception & e){
            throw ImpossibleException();
        }
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
        return ;
    }
    std::cout << static_cast<double>(d);
    if (d - static_cast<int>(d) == 0)
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void    Conversion::toFloat()
{
    float f = 0.0f;
    try{
        std::cout << "float: ";
        if (!_type)
            throw ImpossibleException();
        try{
            f = std::stof(_value);
        } catch (std::exception & e){
            throw ImpossibleException();
        }
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
        return ;
    }
    std::cout << static_cast<float>(f);
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
}

