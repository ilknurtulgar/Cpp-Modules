#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPoint = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = roundf(f * (1 << this->bits));
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = i << this->bits;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fixed)
        this->fixedPoint = fixed.fixedPoint;
    return (*this);
}

int Fixed::toInt(void) const
{
    return (this->fixedPoint >> this->bits);
}

float Fixed::toFloat(void) const 
{
    return (float)(this->fixedPoint / (float)(1 << this->bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}