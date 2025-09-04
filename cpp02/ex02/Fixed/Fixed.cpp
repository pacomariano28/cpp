/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:36:00 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/28 14:12:32 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : __fixedPointNumber(0) {}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int i) {
	__fixedPointNumber = i << __fractBits;
}

Fixed::Fixed(const float f) {
	__fixedPointNumber = roundf(f * (1 << __fractBits));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->__fixedPointNumber = other.__fixedPointNumber;
    return *this;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(__fixedPointNumber) / (1 << __fractBits);
}

// COMPARISON OPERATORS ---------------------------------------------------

bool Fixed::operator>(const Fixed &other) const {
	return this->__fixedPointNumber > other.__fixedPointNumber;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->__fixedPointNumber < other.__fixedPointNumber;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->__fixedPointNumber >= other.__fixedPointNumber;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->__fixedPointNumber <= other.__fixedPointNumber;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->__fixedPointNumber == other.__fixedPointNumber;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->__fixedPointNumber != other.__fixedPointNumber;
}

// ARITHMETIC OPERATORS ---------------------------------------------------

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// INCREMENT OPERATORS ---------------------------------------------------

Fixed& Fixed::operator++() {
    __fixedPointNumber++;
    return *this;
}

Fixed& Fixed::operator--() {
    __fixedPointNumber--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    __fixedPointNumber++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    __fixedPointNumber--;
    return temp;
}

// MIN MAX FUNCTIONS ---------------------------------------------------


Fixed& Fixed::min(Fixed &a, Fixed  &b) {
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed  &b) {
    return ((a > b) ? a : b);
}

const 	Fixed& Fixed::min(const Fixed &a, const Fixed  &b) {
    return ((a < b) ? a : b);
}

const 	Fixed& Fixed::max(const Fixed &a, const Fixed  &b){
    return ((a > b) ? a : b);
}

