/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:28:39 by frmarian          #+#    #+#             */
/*   Updated: 2025/08/27 12:28:40 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	Harl(void);
	void	complain(std::string level);
};

#endif