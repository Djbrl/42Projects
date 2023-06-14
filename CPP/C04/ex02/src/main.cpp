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
	// Animal test = Animal();
	Animal* array[6];
	for(int i = 0; i < 6; i++)
	{
		if (i <= 2)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		std::cout << std::endl;
		delete array[i];
	}
	// basic
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << "end\n";
	// return ;

	// DEEP COPY TEST
	Cat test  = Cat();
	std::string idea = test.getIdea(99);
	std::cout << idea << std::endl;

	Cat test2  = Cat();
	std::string idea2 = test2.getIdea(99);
	std::cout << idea2 << std::endl;

	test = test2;
	std::cout << test.getIdea(99) << std::endl;
}
