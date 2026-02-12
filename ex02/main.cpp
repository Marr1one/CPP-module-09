/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:53:33 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 18:46:00 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// bool isNumber(char *str)
// {
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (!isdigit(str[i])&& !isspace(str[i]))
//         {
//             std::cout << "DEBUG str[i] => {" << str[i] << "}\n";
//             return (false);
//         }
//     }
//     return (true);
// }

bool isNumberString(std::string str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i])&& !isspace(str[i]))
        {
            std::cout << "DEBUG str[i] => {" << str[i] << "}\n";
            return (false);
        }
    }
    return (true);
}

bool parser_vector(std::vector<std::string> vect)
{
    for(size_t i = 0; i < vect.size() ; i++)
    {
        if (!isNumberString(vect[i]))
        {
            std::cout << "DEBUG  argv[i] => {" << vect[i] << "}\n";
            return (false);
        }
    }
    return (true);
}

// bool parser(int argc, char **argv)
// {
//     for(int i = 1; i < argc ; i++)
//     {
//         if (!isNumber(argv[i]))
//         {
//             std::cout << "DEBUG  argv[i] => {" << argv[i] << "}\n";
//             return (false);
//         }
//     }
//     return (true);
// }

std::vector<std::string> argv_to_string(int argc ,char **argv)
{
    std::vector<std::string> res;
    for(int i = 1; i < argc ; i++ )
        res.push_back(argv[i]);
    return (res);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (std::cerr << "Error\n not enough args\n", 1);
    std::vector<std::string> args = argv_to_string(argc ,argv);
    if (argc == 2)
    {
        std::vector<std::string> splitted;
        splitted = split(args);
        std::cout << "after split\n";
        show_vector(splitted);
        args = splitted;
    }
    if (!parser_vector(args))
        return (std::cerr << "entrees invalides\n", 1);
    Merge m;
    m.makePairs(args);
    m.displayPairs();
    m.sort_smalls();
    m.sort_bigs();
    m.mergeInsert();
    std::cout << "smalls after merge insert\n";
    show_vector(m.getSmalls());
    return (0);
}

// parser lentree
// trier avec Ford-johnson algo merge insertion