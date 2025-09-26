#include "Serializer.hpp"

// COF ----------------------------------------------------------------------------------------------------

Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) { 
	(void)other;
	return *this;
}
Serializer::~Serializer(void) {}

// DATA ----------------------------------------------------------------------------------------------------

Serializer::Data::Data(double value) : value(value) {}

// METHODS -------------------------------------------------------------------------------------------------

uintptr_t				Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data*		Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}