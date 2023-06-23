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

#include "../include/Harl.hpp"

int main()
{
    Harl dude = Harl();

    dude.complain("DEBUG");
    dude.complain("INFO");
    dude.complain("WARNING");
    dude.complain("ERROR");
    dude.complain("");
    dude.complain("sdadsa");
    return 0;
}