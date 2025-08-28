#include "Fixed.hpp"

Fixed::Fixed() : __fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) {
	std::cout << "Int constructor called" << std::endl;
	__fixedPointNumber = intNum << __fractBits;
}

Fixed::Fixed(const float floatNum) {
	std::cout << "Float constructor called" << std::endl;
	__fixedPointNumber = roundf(floatNum * (1 << __fractBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other)
		__fixedPointNumber = other.__fixedPointNumber;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

float Fixed::toFloat(void) const {
    return (float)__fixedPointNumber / (1 << __fractBits);
}

int Fixed::toInt(void) const {
    return __fixedPointNumber >> __fractBits;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}