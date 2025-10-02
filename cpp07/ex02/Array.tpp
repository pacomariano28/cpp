#include "Array.hpp"
#include <exception>
#include <cstddef>

// COF ------------------------------------------------------------------------------------------------------

template<typename T>
Array<T>::Array(void) : _data(NULL),  _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _data(NULL),  _size(n) {
	if (n > 0)
		_data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _data(NULL), _size(other._size) {
    if (_size > 0) {
        _data = new T[_size]();
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = (_size > 0) ? new T[_size]() : NULL;
        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array(void) {
	delete[] _data;
}

// METHODS ------------------------------------------------------------------------------------------------------

template<typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw OutOfRange();
	return _data[idx];
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= _size)
		throw OutOfRange();
	return _data[idx];
}

template<typename T>
unsigned int	Array<T>::size() const {
	return _size;
}
