#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array(void);

		T&				operator[](unsigned int idx);
		const T&		operator[](unsigned int idx) const;
		unsigned int	size() const;
};

#endif