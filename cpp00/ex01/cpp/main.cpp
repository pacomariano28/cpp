/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:10:14 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 14:13:03 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/lib.hpp"

std::string	main_menu() {
	
	std::string option;

	main_msg();
	get_input(option);
	return option;
}

void	exec_option(std::string option, PhoneBook& myPhoneBook) {

	if (option == ADD)
        add(myPhoneBook);
    else if (option == SEARCH)
        search(myPhoneBook);
    else if (option == EXIT)
        exit(EXIT_SUCCESS);
    else
		std::cout << "\033[1;31m\n\nInvalid option.\033[0m\n" << std::endl;
	return ;
}

int		main(void) {

	PhoneBook	myPhoneBook;
	std::string option;

	welcome_msg();
	while (true) {
        option = main_menu();
		exec_option(option, myPhoneBook);
	}
}