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

static int nbCat = 0;

Cat::Cat():Animal()
{
    type = "Cat";
    brain = new Brain();
    nbCat +=1;
    std::cout << "(Default Cat Constructor) Cat #" << nbCat << std::endl;
}


Cat::Cat(const Cat& a):Animal()
{
   type = a.type;
   brain = new Brain(*(a.brain));
   nbCat += 1;
   std::cout << "(Default Cat Constructor 2) Cat #" << nbCat << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    if (this != &a)
    {
        type = a.type;
        Brain *tmp = new Brain();
        tmp = a.brain;
        *brain = *tmp;        
        nbCat += 1;
        std::cout << "(Copy Cat Constructor) Cat #" << nbCat << std::endl;
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << type << " was destroyed" << std::endl;
}


void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}


std::string Cat::getIdea(int i)
{
    if (i >= 0 && i < 100)
        return brain->returnIdea(i);
    else
        return "";
}