/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:41:54 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 14:11:47 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
#define LIB_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"
#include "Phonebook.hpp"

// Opciones del menú principal
#define ADD "1"
#define SEARCH "2"
#define EXIT "3"

// Mensajes de UI
void welcome_msg();
void main_msg();
void add_msg();
void firstName_msg();
void lastName_msg();
void nickname_msg();
void phoneNumber_msg();
void darkestSecret_msg();
void contact_success_msg();
void search_msg();

// Funciones de lógica
void add(PhoneBook& myPhoneBook);
void search(PhoneBook& myPhoneBook);
void get_input(std::string& value);

// main.cpp
std::string main_menu();
void exec_option(std::string option, PhoneBook& myPhoneBook);

#endif