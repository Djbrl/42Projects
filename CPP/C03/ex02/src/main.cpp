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

# include "../include/ScavTrap.hpp"
# include "../include/FragTrap.hpp"

int main()
{
    ClapTrap dude = ClapTrap();
    ClapTrap jeff = dude;
    ClapTrap ken (jeff);
    ScavTrap scavy = ScavTrap();

    dude.attack("greg");
    jeff.attack("greg");
    ken.attack("ryu");
    ken.setAD(12312);
    ken.attack("ryu");
    ken.takeDamage(231321);
    ken.takeDamage(123312);
    ken.takeDamage(123123);
    ken.beRepaired(12312311);
    ken.beRepaired(213123);
    ken.takeDamage(123123123);
    scavy.guardGate();
    scavy.guardGate();
    scavy.guardGate();
    scavy.attack("greg");

	FragTrap bot;
	FragTrap Dante("Dante");
	Dante.highFivesGuys();
    return 0;
}