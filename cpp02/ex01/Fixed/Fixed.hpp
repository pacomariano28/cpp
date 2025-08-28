#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
#include <iostream>
#include <cmath>

class Fixed {
	private:
	int					__fixedPointNumber;
	static const int	__fractBits = 8;

	public:
	Fixed();
	Fixed(const int intNum);
	Fixed(const float floatNum);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& 				operator=(const Fixed &other);
	float				toFloat(void) const;
	int					toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif