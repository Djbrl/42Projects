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

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	if (this != &src)
		*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		type = src.type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << type << " destroyed (Parent class)" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout <<  "random WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::setType(std::string str)
{
	this->type = str;
}

std::ostream	&operator<<(std::ostream &stream, const WrongAnimal &a)
{
	std::cout << "<< operator overload\n";
	return stream;
}