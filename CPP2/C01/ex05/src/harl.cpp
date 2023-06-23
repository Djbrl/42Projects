/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:24 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:35:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "[DEBUG]" << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*fnptr[4])();
    fnptr[0] = &Harl::debug;
    fnptr[1] = &Harl::info;
    fnptr[2] = &Harl::warning;
    fnptr[3] = &Harl::error;

    std::string type[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (type[i] == level)
		{
			(this->*fnptr[i])();
			break ;
		}
	}
}