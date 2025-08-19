/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:59:00 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/06 11:34:34 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av) {

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++){
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)std::toupper(av[i][j]);
			if (i != (ac - 1))
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}