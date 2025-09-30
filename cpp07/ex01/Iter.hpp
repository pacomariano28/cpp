#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T, typename F>
void		iter(T* arr, size_t len, F func){
	for(size_t i = 0; i <len; ++i)
		func(arr[i]);
}

#endif