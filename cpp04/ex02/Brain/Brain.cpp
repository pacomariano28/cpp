#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain &other) {
	if (this != &other)
		*__ideas = *(other.__ideas);
}

Brain& Brain::operator=(Brain &other) {
	if (this != &other)
		*__ideas = *(other.__ideas);
	return *this;
}

Brain::~Brain(void) {}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100)
        return "";
    return __ideas[index];
}

void Brain::setIdea(int index, std::string const &idea) {
    if (index < 0 || index >= 100)
        return;
    __ideas[index] = idea;
}