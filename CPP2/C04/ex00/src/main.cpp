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

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

int main ()
{
    {

        Animal instantiateTest = Animal();
        std::cout << instantiateTest.getType() << std::endl;
        instantiateTest.makeSound();

        Cat smolCat = Cat();
        std::cout << smolCat.getType() << std::endl;
        smolCat.makeSound();

        Dog smolDog = Dog();
        std::cout << smolDog.getType() << std::endl;
        smolDog.makeSound();
    }
    {
        const Animal constTest = Dog();
        constTest.makeSound();
        const Animal constTest2 = Cat();
        constTest2.makeSound();
    }
    {
        const WrongCat test = WrongCat();
        test.makeSound();
    }   
    return 0;
}