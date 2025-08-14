/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:03:42 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/12 13:52:23 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/Contact.hpp"

Contact::Contact() {}

void		Contact::setFirstName(const std::string& firstName) {
	__firstName = firstName;
}

void		Contact::setLastName(const std::string& lastName) {
	__lastName = lastName;
}

void		Contact::setNickname(const std::string& nickname) {
	__nickname = nickname;
}

void		Contact::setPhoneNumber(const std::string& phoneNumber) {
	__phoneNumber = phoneNumber;
}

void		Contact::setDarkestSecret(const std::string& darkestSecret) {
	__darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
	return __firstName;
}

std::string Contact::getLastName() const {
	return __lastName;
}

std::string Contact::getNickname() const {
	return __nickname;
}

std::string Contact::getPhoneNumber() const {
	return __phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return __darkestSecret;
}

bool		Contact::isEmpty() const {
	return getFirstName().empty();
}

void Contact::show() const {
    const std::string yellow_bold = "\033[1;33m";
    const std::string white_normal = "\033[0;37m";
    const std::string reset = "\033[0m"; 

    std::cout << yellow_bold << "Name:" << reset << " " << white_normal << __firstName << reset << std::endl;
    std::cout << yellow_bold << "Last Name:" << reset << " " << white_normal << __lastName << reset << std::endl;
    std::cout << yellow_bold << "Nickname:" << reset << " " << white_normal << __nickname << reset << std::endl;
    std::cout << yellow_bold << "Phone Number:" << reset << " " << white_normal << __phoneNumber << reset << std::endl;
    std::cout << yellow_bold << "Darkest Secret:" << reset << " " << white_normal << __darkestSecret << reset << std::endl;
	std::cout << "\n";
}

