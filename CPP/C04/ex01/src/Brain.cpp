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

#include "../include/Brain.hpp"

Brain::Brain()
{
    std::cout << "(Default Brain Constructor)" << std::endl;
}

Brain::Brain(const Brain& b)
{
    *this = b;
    std::cout << "(Copy Brain Constructor)" << std::endl;
}

Brain& Brain::operator=(const Brain& b)
{
    if (this != &b)
        *ideas = *b.ideas;
    return (*this);
}

Brain::~Brain()
{}

std::string* Brain::getIdeas()
{
	return (ideas);
}