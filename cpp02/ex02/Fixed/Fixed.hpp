#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
	private:
	int					__fixedPointNumber;
	static const int	__fractBits = 8;

	public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();

	Fixed&	operator=(const Fixed &other);
	float	toFloat() const;

	bool			operator>(const Fixed &other) const;
	bool			operator<(const Fixed &other) const;
	bool			operator>=(const Fixed &other) const;
	bool			operator<=(const Fixed &other) const;
	bool			operator==(const Fixed &other) const;
	bool			operator!=(const Fixed &other) const;

 	Fixed			operator+(const Fixed &other) const;
	Fixed			operator-(const Fixed &other) const;
	Fixed			operator*(const Fixed &other) const;
	Fixed			operator/(const Fixed &other) const;

	Fixed			&operator++(void);
	Fixed			&operator--(void);
	/* Fixed			operator++(int i); */
	/* Fixed			operator--(int i); */
	Fixed			operator++(int);
	Fixed			operator--(int);	

	static 			Fixed& min(Fixed &a, Fixed  &b);
	static 			Fixed& max(Fixed &a, Fixed  &b);
	static const 	Fixed& min(const Fixed &a, const Fixed  &b);
	static const 	Fixed& max(const Fixed &a, const Fixed  &b);
};

std::ostream		&operator<<(std::ostream &out, const Fixed &fixed);

#endif