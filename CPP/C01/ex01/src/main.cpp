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

void kill_horde(Zombie *horde)
{
    delete [] horde;
}

int main(int ac, char **av)
{
    Zombie *horde = zombieHorde(10, "Yamcha");
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    kill_horde(horde);
    return 0;
}
