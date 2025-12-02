/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:53:33 by marwan            #+#    #+#             */
/*   Updated: 2025/11/30 18:06:33 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isNumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i])&& !isspace(str[i]))
        {
            std::cout << "DEBUG str[i] => {" << str[i] << "}\n";
            return (false);
        }
    }
    return (true);
}

bool parser(int argc, char **argv)
{
    for(int i = 1; i < argc ; i++)
    {
        if (!isNumber(argv[i]))
        {
            std::cout << "DEBUG  argv[i] => {" << argv[i] << "}\n";
            return (false);
        }
    }
    return (true);
}


int main(int argc, char **argv)
{
    if (argc < 2)
        std::cerr << "Error\n not enough args\n";
    // if (argc == 2)
        // split(argv[1], ' ');
    if (!parser(argc , argv))
    {
        std::cerr << "entrees invalides\n";
        return (1);
    }
    std::cout << "valid entry\n";
    Merge m;
    m.makeTab(argc, argv);
    m.displayTab();
    m.makePairs(argc, argv);
    m.displayPairs();
    m.sort_bigs();
    m.sort_smalls();
    return (0);
}

// parser lentree
// trier avec Ford-johnson algo merge insertion