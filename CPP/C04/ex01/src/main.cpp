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

int main()
{
	Animal* array[6];
	Dog*	test_deep_cpy;

	std::cout << "\n	-	-	-	-	-	-	-	-\n" << std::endl;
	for(int i = 0; i < 6; i++)
	{
		if (i <= 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << std::endl;
	}

	test_deep_cpy = new Dog((*dynamic_cast<Dog *>(array[0])));
	std::cout << "\n	-	-	-	-	-	-	-	-\n" << std::endl;
	for(int i = 0; i < 6; i++)
		delete array[i];
	std::cout << "\n	-	-	-	-	-	-	-	-\n" << std::endl;
	std::cout << "## The deep copy is illustrated by the existence of the string copied from array[0].\
 While this instance was deleted : \n" << *test_deep_cpy->getBrain()->getIdeas() << std::endl;
 	std::cout << "\n	-	-	-	-	-	-	-	-\n" << std::endl;
	delete test_deep_cpy;
}