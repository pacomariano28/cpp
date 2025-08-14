/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:27:56 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 14:01:12 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/Phonebook.hpp"

PhoneBook::PhoneBook() : __contactCount(0) {}

static std::string format_field(const std::string& str) {
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void	PhoneBook::addContact(const Contact& newContact) {
	__contacts[__contactCount % 8] = newContact;
	__contactCount++;
}

Contact PhoneBook::getContact(int index) const {
	if (index < (__contactCount % 8) && index >= 0)
		return (__contacts[index]);
	return(Contact());
}

size_t		PhoneBook::getCount() const {
    return (__contactCount % 8);
}

void	PhoneBook::showContacts() const {
    size_t	i;
    size_t	end;

    i = 0;
    end = getCount();

    std::cout << std::endl;
    std::cout << "\033[1;36m┌──────────┬──────────┬──────────┬──────────┐\033[0m" << std::endl;
    std::cout << "\033[1;36m│\033[1;33m   Index   \033[1;36m│\033[1;33m First Name\033[1;36m│\033[1;33m Last Name \033[1;36m│\033[1;33m Nickname  \033[1;36m│\033[0m" << std::endl;
    std::cout << "\033[1;36m├──────────┼──────────┼──────────┼──────────┤\033[0m" << std::endl;

    if (end == 0) {
        std::cout << "\033[1;36m│\033[1;31m                  No contacts found                  \033[1;36m│\033[0m" << std::endl;
    } else {
        while (i < end) {
            std::cout << "\033[1;36m│\033[1;37m" << std::setw(10) << i + 1 << "\033[1;36m│\033[1;37m"
                << std::setw(10) << format_field(__contacts[i].getFirstName()) << "\033[1;36m│\033[1;37m"
                << std::setw(10) << format_field(__contacts[i].getLastName()) << "\033[1;36m│\033[1;37m"
                << std::setw(10) << format_field(__contacts[i].getNickname()) << "\033[1;36m│\033[0m" << std::endl;
            i++;
        }
    }
    
    std::cout << "\033[1;36m└──────────┴──────────┴──────────┴──────────┘\033[0m" << std::endl;
}