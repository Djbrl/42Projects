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

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
}

Cat::Cat(const Cat &c) : Animal()
{
    if (this != &c)
        *this = c;
}

Cat& Cat::operator=(const Cat &c)
{
    if (this != &c)
        type = c.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << type << " was destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}