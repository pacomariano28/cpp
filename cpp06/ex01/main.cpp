#include "Serializer/Serializer.hpp"
#include <iostream>

int main() {
    // Crear objeto Data
    Serializer::Data data(42.5);
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << "Value: " << data.value << std::endl;
    
    // Serializar
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "\nSerialized: " << serialized << std::endl;
    
    // Deserializar
    Serializer::Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    
    // Verificar que son el mismo puntero
    std::cout << "\nPointers match: " << (&data == deserialized ? "YES" : "NO") << std::endl;
    
    return 0;
}