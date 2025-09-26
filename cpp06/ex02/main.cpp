#include "Base/Base.hpp"
#include "EmptyClasses/A.hpp"
#include "EmptyClasses/B.hpp"
#include "EmptyClasses/C.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Type Identification with Error Cases ===" << std::endl;
    
    // =================== CASO 1: Puntero NULL ===================
    std::cout << "\n--- Test 1: NULL pointer ---" << std::endl;
    Base* null_ptr = NULL;
    
    std::cout << "Identify NULL pointer: ";
    identify(null_ptr);  // ¿Qué pasa? Puede hacer crash
    
    // =================== CASO 2: Punteros válidos ===================
    std::cout << "\n--- Test 2: Valid pointers ---" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    std::cout << "A pointer: ";
    identify(a);
    std::cout << "A reference: ";
    identify(*a);
    
    std::cout << "B pointer: ";
    identify(b);
    std::cout << "B reference: ";
    identify(*b);
    
    std::cout << "C pointer: ";
    identify(c);
    std::cout << "C reference: ";
    identify(*c);
    
    // =================== CASO 3: Referencias a punteros NULL ===================
    std::cout << "\n--- Test 3: Dereferencing NULL (DANGEROUS!) ---" << std::endl;
    try {
        // ¡PELIGROSO! Esto va a crashear
        std::cout << "Trying to dereference NULL: ";
        //identify(*null_ptr);  // ← Descomenta si quieres ver el crash
        std::cout << "SKIPPED - would cause segmentation fault" << std::endl;
    } catch (...) {
        std::cout << "Caught exception from NULL dereference" << std::endl;
    }
    
    // =================== CASO 4: Generate random múltiples veces ===================
    std::cout << "\n--- Test 4: Random generation ---" << std::endl;
    for (int i = 0; i < 10; ++i) {
        Base* random_obj = generate();
        
        std::cout << "Random object " << (i + 1) << " - Pointer: ";
        identify(random_obj);
        
        std::cout << "Random object " << (i + 1) << " - Reference: ";
        identify(*random_obj);
        
        delete random_obj;
    }
    
    // =================== CASO 5: Memory leak test ===================
    std::cout << "\n--- Test 5: Memory management ---" << std::endl;
    std::cout << "Creating objects without deletion (memory leak test):" << std::endl;
    
    for (int i = 0; i < 3; ++i) {
        Base* obj = generate();
        std::cout << "Object " << (i + 1) << ": ";
        identify(obj);
        // ¡No delete! Esto es un memory leak intencionado para testing
    }
    std::cout << "Memory leaked intentionally for testing purposes" << std::endl;
    
    // =================== CASO 6: Puntero a objeto ya eliminado ===================
    std::cout << "\n--- Test 6: Dangling pointer (DANGEROUS!) ---" << std::endl;
    Base* dangling_ptr = new A();
    std::cout << "Before delete: ";
    identify(dangling_ptr);
    
    delete dangling_ptr;
    // dangling_ptr ahora apunta a memoria liberada
    
    std::cout << "After delete (dangling pointer): ";
    // identify(dangling_ptr);  // ← PELIGROSO! Descomenta para ver comportamiento indefinido
    std::cout << "SKIPPED - would cause undefined behavior" << std::endl;
    
    // =================== LIMPIEZA ===================
    delete a;
    delete b;
    delete c;
    // null_ptr no necesita delete (es NULL)
    
    std::cout << "\n=== Testing completed ===" << std::endl;
    
    return 0;
}