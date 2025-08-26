#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: invalid params" << std::endl;
		return 1;
	}

	std::string	fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream file(fileName.c_str());

	if(!file) {
		std::cerr << "Error opening " << fileName << std::endl;
		return 1;
	}

	std::string	fullText;
	std::string	line;

	while (std::getline(file, line)) {
		if (!fullText.empty())
			fullText += "\n";
    	fullText += line;
	}

	std::string finalText;
	
	
	size_t index = fullText.find(s1);
	size_t start = 0;

	if (index == std::string::npos) {
		std::cout << "mostro" << std::endl;
		return 0;
	}

	while(index != std::string::npos) {
		finalText += fullText.substr(start, index);
		finalText += s2;
		start = index + s1.length();
		index = fullText.find(s1, start);
	}

	std::cout << finalText << std::endl;

	return 0;
}