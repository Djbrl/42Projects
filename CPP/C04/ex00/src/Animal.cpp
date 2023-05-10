/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:37:43 by user42            #+#    #+#             */
/*   Updated: 2022/01/27 15:05:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/Fixed.hpp"

#include "../include/Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(const Animal &src)
{
	if (this != &src)
		*this = src;
}

Animal	&Animal::operator=(const Animal &src)
{
	if (this != &src)
		type = src.type;
	return(*this);
}

Animal::~Animal()
{
	std::cout << type << " destroyed (Parent class)" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout <<  "random animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::setType(std::string str)
{
	this->type = str;
}