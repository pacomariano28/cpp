/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:12:32 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 12:31:04 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {

private:
	Contact __contacts[8];
	int		__contactCount;

public:
	PhoneBook();

	void	addContact(const Contact& newContact);
	Contact	getContact(size_t index) const;
	size_t	getCount() const;
	void	showContacts() const;
};

#endif