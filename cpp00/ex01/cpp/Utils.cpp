/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:59:59 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/14 14:13:55 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/lib.hpp"

std::string trim(const std::string& str) {
    if (str.empty())
        return str;
    
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
        return "";
    
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}

void get_input(std::string& value) {
    std::getline(std::cin, value);
    if (std::cin.eof()) {
        std::cout << "EOF detected... exiting.\n" << std::endl;
        exit(EXIT_SUCCESS);
    }
    value = trim(value);
}