/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:23:20 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/27 11:56:46 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

bool validateArguments(int ac) {
    if (ac != 4) {
        std::cerr << "Error: invalid params" << std::endl;
        return false;
    }
    return true;
}

std::string readFile(const std::string& fileName) {
    
	std::ifstream file(fileName.c_str());
    if(!file) {
        std::cerr << "Error opening " << fileName << std::endl;
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string	fileContent = buffer.str();
    file.close();

    return fileContent;
}

std::string replaceText(const std::string& fileContent, const std::string& s1, const std::string& s2) {
	
    std::string finalContent;
    size_t index = fileContent.find(s1);
    size_t start = 0;

    if (index == std::string::npos) {
        std::cout << "No matches found." << std::endl;
        return fileContent;
    }

    while(index != std::string::npos) {
        finalContent.append(fileContent.substr(start, (index - start)));
        finalContent.append(s2);
        start = index + s1.length();
        index = fileContent.find(s1, start);
    }
    finalContent.append(fileContent.substr(start));

    return finalContent;
}

void writeOutput(const std::string& finalContent) {
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << finalContent;
        outFile.close();
        std::cout << "Output written to output.txt" << std::endl;
    } else {
        std::cout << finalContent << std::endl;
    }
}

int main(int ac, char **av) {
    if (!validateArguments(ac))
        return 1;

    std::string	fileName = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::string fileContent = readFile(fileName);
    if (fileContent.empty())
        return 1;

    std::string finalContent = replaceText(fileContent, s1, s2);
    writeOutput(finalContent);

    return 0;
}