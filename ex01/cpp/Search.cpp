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

static bool    notDigit(const std::string& str) {
    return (str.empty() || str.find_first_not_of("0123456789") != std::string::npos);
}

static bool notInRange(size_t contactIndex, size_t contactCount) {
    return (contactIndex == 0 || contactIndex > contactCount);
}

void	search(PhoneBook &myPhoneBook) {
    
    std::string option;
    size_t contactIndex, contactCount;

    contactCount = myPhoneBook.getCount();

    if (contactCount == 0) {
        std::cout << "\033[1;31m\nNo contacts available.\033[0m" << std::endl;
        return;
    }

    myPhoneBook.showContacts();

    while (true) {
        search_msg();
        get_input(option);

        if (notDigit(option)) {
            std::cout << "\033[1;31m\nError: index must be a number.\033[0m" << std::endl;
            continue;
        }

        std::istringstream iss(option);
        iss >> contactIndex;

        if (notInRange(contactIndex, contactCount)) {
            std::cout << "\033[1;31m\nError: index out of range.\033[0m" << std::endl;
            continue;
        }

        myPhoneBook.getContact(contactIndex - 1).show();
        break;
    }
}