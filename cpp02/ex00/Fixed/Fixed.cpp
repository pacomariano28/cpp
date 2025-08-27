#include "Fixed.hpp"

Fixed::Fixed(void) {
	__fixedPointNumber = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	__fixedPointNumber = other.__fixedPointNumber;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	__fixedPointNumber = other.__fixedPointNumber;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return __fixedPointNumber;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	__fixedPointNumber = raw;
}