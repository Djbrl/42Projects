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

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
}

Dog::Dog(const Dog &d) : Animal()
{
    if (this != &d)
        *this = d;
}

Dog &Dog::operator=(const Dog& d)
{
    if (this != &d)
        type = d.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << type << " was destroyed" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "bark" << std::endl;
}