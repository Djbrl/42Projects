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

#include "../include/sed.hpp"

int main(int ac, char **av)
{
    std::ifstream infile(av[1]);
    std::string s1 = av[2], s2 = av[3], res = av[1], file, line;;

    if (ac != 4 || !infile.is_open())
    {
        std::cout << "Invalid arguments\n";
        return 0;
    }

    //read file
    if (infile.is_open())
    {
        while (std::getline(infile, line))
            file += line + "\n";
        infile.close();
    }
    res += ".replace";
    if (s1.empty() || s2.empty())
    {
        std::ofstream outfile(res);
        if (outfile.is_open())
        {
            outfile << file;
            outfile.close();
        }
        else
            std::cout << "Error while creating outfile\n";
        return 0;
    }
    else
    {
        std::string result = "";
        int len1 = s1.length();
        int len2 = s2.length();
        int i = 0;
        while (i < file.length()) {
            if (file.substr(i, len1) == s1)
            {
                result += s2;
                i += len1;
            }
            else
                result += file[i++];
        }
        std::ofstream outfile(res);
        if (outfile.is_open())
        {
            outfile << result;
            outfile.close();
        }
        else
            std::cout << "Error while creating outfile\n";       
    }
    return 0;
}