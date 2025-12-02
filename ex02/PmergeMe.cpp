/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2025/11/30 18:06:11 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Merge::Merge(){};

Merge::~Merge(){};


void Merge::displayPairs()
{
    std::vector<std::pair<int,int>> pairs = getPairs();
    
    
     for (int i = 0; i < pairs.size(); i ++)
    {
        std::cout << "("  << pairs[i].first << ", " << pairs[i].second << ")\n";
    }
}

void Merge::displayTab()
{
    std::vector<char *> tab = getTab();
    
     for (int i = 0; i < tab.size(); i++)
    {
        std::cout << tab[i] << std::endl;
    }
}

std::vector<std::pair<int, int>> Merge::getPairs()
{
    return (this->_pairs);
}

std::vector<char*> Merge::getTab()
{
    return (this->_tab);
}

void Merge::makeTab(int argc, char **argv)
{
    std::vector<char*> res;
    for (int i = 1; i < argc;   i++)
    {
        // peut etre fait dans le parsing en vrai
        res.push_back(argv[i]);
    }
    _tab = res;
}


std::vector<std::pair<int, int>> Merge::makePairs(int argc ,char **argv)
{
    std::vector<std::pair<int, int>> pairs;
    int nb_args = argc - 1;

    if (nb_args % 2 != 0)
    {
        _leftover = atoi(argv[argc - 1]);
        std::cout << "leftover => "<<_leftover << std::endl;
        for (int i = 1; i + 1 < argc - 1 ; i += 2)
        {
            int a = atoi(argv[i]);
            int b = atoi(argv[i + 1]);
            if(a > b)
                pairs.push_back(std::make_pair(b,a));
            else
                pairs.push_back(std::make_pair(a,b));
        }
    }
    else 
    {
        for (int i = 1; i + 1 < argc ; i += 2)
        {
            int a = atoi(argv[i]);
            int b = atoi(argv[i + 1]);
            if(a > b)
                pairs.push_back(std::make_pair(b,a));
            else
                pairs.push_back(std::make_pair(a,b));
        }
    }
    _pairs = pairs;
    return (pairs);
}




void Merge::sort_bigs()
{
    std::vector<int> res;
    std::vector<std::pair<int, int>>pairs = getPairs();

    
    for(int i = 0; i < pairs.size() ; i++)
    {
        res.push_back(pairs[i].second);
    }
    std::sort(res.begin(), res.end());
    std::cout << "BIGS\n";
    show_vector(res);
    _bigs = res;
}

void Merge::sort_smalls()
{
    std::vector<int> res;
    std::vector<std::pair<int, int>>pairs = getPairs();

    
    for(int i = 0; i < pairs.size() ; i++)
    {
        res.push_back(pairs[i].first);
    }
    std::sort(res.begin(), res.end());
    std::cout << "SMALLS\n";
    show_vector(res);
    _smalls = res;
}