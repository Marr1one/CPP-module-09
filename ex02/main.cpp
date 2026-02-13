/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:53:33 by marwan            #+#    #+#             */
/*   Updated: 2026/02/13 17:23:46 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
std::vector<std::string> argv_to_string(int argc ,char **argv)
{
    std::vector<std::string> res;
    for(int i = 1; i < argc ; i++ )
        res.push_back(argv[i]);
    return (res);
}
template<typename T>
void cleanshow(const std::vector<T>&str)
{
	for(size_t i = 0;i <str.size();i++)
	{
		std::cout <<str[i];
		if (i+1<str.size())std::cout <<" ";
	}
	std::cout << std::endl;
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
        //show_vector(splitted);
        args = splitted;
    }
    if (!parser_vector(args))
        return (std::cerr << "Invalid inputs\n", 1);
    Merge m;
	std::cout <<"Before :";
	cleanshow(args);
	clock_t start = std::clock();
    m.makePairs(args);
    //m.displayPairs();
    m.sort_smalls();
    m.sort_bigs();
    m.mergeInsert();
    //std::cout << "smalls after merge insert\n";
    //show_vector(m.getSmalls());
	clock_t end = std::clock();
	double time = static_cast<double>(end-start) / CLOCKS_PER_SEC * 1000000;
	std::cout <<"After :";
	cleanshow(m.getSmalls());
	std::cout << "Time to process a range of "
		<< args.size() << " elements with std::vector :"
		<< time << " us" << std::endl;
    return (0);
}

// parser lentree
// trier avec Ford-johnson algo merge insertion