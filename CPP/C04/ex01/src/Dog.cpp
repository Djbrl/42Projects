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

static int nbDog = 0;

Dog::Dog():Animal()
{
    type = "Dog";
    brain = new Brain();
    nbDog +=1;
    std::cout << "(Default Dog Constructor) Dog #" << nbDog << std::endl;
}


Dog::Dog(const Dog& a):Animal()
{
   type = a.type;
   brain = new Brain(*(a.brain));
   nbDog += 1;
   std::cout << "(Default Dog Constructor 2) Dog #" << nbDog << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
    if (this != &a)
    {
        type = a.type;
        Brain *tmp = new Brain();
        tmp = a.brain;
        *brain = *tmp;
        nbDog += 1;
        std::cout << "(Copy Dog Constructor) Dog #" << nbDog << std::endl;
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << type << " was destroyed" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "meow" << std::endl;
}

std::string Dog::getIdea(int i)
{
    if (i >= 0 && i < 100)
        return brain->returnIdea(i);
    else
        return "";
}

// Brain* Dog::getBrain() const
// {
//     if (brain)
//         return (brain);
//     return (NULL);
// }