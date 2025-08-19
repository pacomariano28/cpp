/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:03:46 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/11 14:21:05 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private: 
	std::string __firstName;
	std::string __lastName;
	std::string __nickname;
	std::string __phoneNumber;
	std::string __darkestSecret;

public:
	Contact();

	void		setFirstName(const std::string& firstName);
	void		setLastName(const std::string& lastName);
	void		setNickname(const std::string& nickname);
	void		setPhoneNumber(const std::string& phoneNumber);
	void		setDarkestSecret(const std::string& darkestSecret);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	bool		isEmpty() const;
	void		show() const ;
};

#endif