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

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal()
{
    if (this != &c)
        *this = c;
}

WrongCat& WrongCat::operator=(const WrongCat &c)
{
    if (this != &c)
        type = c.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << type << " was destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "wrongmeow" << std::endl;
}