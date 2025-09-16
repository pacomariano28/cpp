#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
	std::string __ideas[100];

	public:
	Brain(void);
	Brain(Brain &other);
	Brain &operator=(Brain &other);
	~Brain(void);

	std::string getIdea(int index) const;         // devuelve la idea en la posición index
	void setIdea(int index, std::string const &idea); // pone una idea en la posición index
};

#endif