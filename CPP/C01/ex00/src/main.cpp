/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsy <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:35:24 by dsy               #+#    #+#             */
/*   Updated: 2023/05/02 19:35:26 by dsy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void    kill(Zombie *victim)
{
    if (victim != NULL)
        delete victim;
}

int main(int ac, char **av)
{
    Zombie goku = Zombie("Goku");
    goku.announce();
    Zombie *yamcha = newZombie("Yamcha");
    kill(yamcha);
    randomChump("Krillin");
    return 0;
}
