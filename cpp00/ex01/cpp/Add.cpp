/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:16:43 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/28 11:28:25 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/lib.hpp"

static void process_data(Contact &newContact, void (Contact::*setter)(const std::string&), std::string& value) {
    get_input(value);
    (newContact.*setter)(value);
}

static void create_contact(Contact &newContact) {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    firstName_msg();
	process_data(newContact, &Contact::setFirstName, firstName);

    lastName_msg();
    process_data(newContact, &Contact::setLastName, lastName);

    nickname_msg();
    process_data(newContact, &Contact::setNickname, nickname);

    phoneNumber_msg();
    process_data(newContact, &Contact::setPhoneNumber, phoneNumber);

    darkestSecret_msg();
    process_data(newContact, &Contact::setDarkestSecret, darkestSecret);

    contact_success_msg();
}

void	add(PhoneBook& myPhoneBook) {

	Contact newContact;

	add_msg();
	create_contact(newContact);
	myPhoneBook.addContact(newContact);
}