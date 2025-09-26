#include "Base.hpp"
#include "../EmptyClasses/A.hpp"
#include "../EmptyClasses/B.hpp"
#include "../EmptyClasses/C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base(void) {}

Base* generate(void) {
	std::srand(std::time(0));
	int choice = std::rand() % 3;

	switch(choice) {
		case 0 : return new A();
		case 1 : return new B();
		case 2 : return new C();
		default: return new A();
	}
}

void identify(Base* ptr) {
	if (dynamic_cast<A*>(ptr) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& ref) {
	try {
			(void)dynamic_cast<A&>(ref);
			std::cout << "A" << std::endl;
		return;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(ref);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception& e) {}

	try {
		(void)dynamic_cast<C&>(ref);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
	
}