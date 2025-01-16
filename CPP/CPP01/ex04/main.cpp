/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:37:37 by nmontiel          #+#    #+#             */
/*   Updated: 2024/05/22 17:59:45 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
	{
        std::ifstream inf(argv[1]);
        if (!inf)
		{
            std::cerr << "Error opening infile" << std::endl;
            return 1;
        }
        std::string outfName = std::string(argv[1]) + ".replace";
        std::ofstream outf(outfName.c_str());
        if (!outf)
		{
            std::cerr << "Error opening outfile" << std::endl;
            inf.close();
            return 1;
        }
        std::string str;
        std::string start(argv[2]);
        std::string end(argv[3]);

        while (std::getline(inf, str))
		{
            replaceAll(str, start, end);
            outf << str << '\n';
        }
        inf.close();
        outf.close();
    }
	else 
	{
        std::cerr << "Invalid number of arguments" << std::endl;
        return 1;
    }
    return 0;
}