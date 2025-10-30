#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		~Array(void);

		T&				operator[](unsigned int idx);
		const T&		operator[](unsigned int idx) const;
		unsigned int	size() const;

		class OutOfRange : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "index out of range!";
				}
		};
};

#endif