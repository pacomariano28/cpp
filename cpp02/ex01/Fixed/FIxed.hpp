#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
	private:
	int					__fixedPointNumber;
	static const int	__fractBits = 8;

	public:
	Fixed(const int intNum);
	Fixed(const float floatNum);
	~Fixed();

	float				toFloat(void) const;
	int					toInt(void) const;
	friend std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
};

#endif