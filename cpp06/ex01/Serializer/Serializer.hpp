#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer(void);

	public:
		struct Data {
            double value;
            
            Data(double value = 0.0);
        };

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif