/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:16:23 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 14:05:41 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/lib.hpp"

void	search(PhoneBook &myPhoneBook) {
	
	std::string option;
	size_t		contactIndex;

	myPhoneBook.showContacts();
	search_msg();
	get_input(option);
	try {
		contactIndex = (std::atoi(option.c_str()));
		if (contactIndex <= myPhoneBook.getCount())
			myPhoneBook.getContact(contactIndex - 1).show();

	} catch (...) {
		std::cout << "Error with the index" << std::endl;
	}
}