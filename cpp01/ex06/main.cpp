/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:46:32 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/27 12:48:49 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

bool validArg(std::string level) {
	const char* levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i) {
		if (level == levels[i])
			return true;
	}
	return false;
}

void	toUppercase(std::string& str) {
	for (size_t i = 0; i < str.length(); ++i)
		str[i] = std::toupper(str[i]);
}

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout
			<< "Error: usage ./harlFilter <DEBUG/INFO/WARNING/ERROR>"
			<< std::endl;
			return 1;
	}
	av++;

	std::string level = *av;
	toUppercase(level);

	if (!validArg(level)) {
		std::cout
			<< "Error: Invalid arg"
			<< std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(level);
	return 0;
}