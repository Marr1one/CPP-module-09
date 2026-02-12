/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 18:47:38 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Merge::Merge() : _has_leftover(false){};

Merge::~Merge(){};


std::vector<std::string> split(std::vector<std::string> args)
{
    std::vector<std::string> res;
    std::stringstream ss(args[0]);
    std::string word;
    while (ss >> word)
        res.push_back(word);
    return (res);
}


void Merge::displayPairs()
{
    std::vector<std::pair<int,int> > pairs = getPairs();
     for (size_t i = 0; i < pairs.size(); i ++)
        std::cout << "("  << pairs[i].first << ", " << pairs[i].second << ")\n";
}

// void Merge::displayTab()
// {
//     std::vector<char *> tab = getTab();
    
//      for (int i = 0; i < tab.size(); i++)
//     {
//         std::cout << tab[i] << std::endl;
//     }
// }

std::vector<std::pair<int, int> > Merge::getPairs() const 
{
    return (this->_pairs);
}

// void Merge::makeTab(int argc, char **argv)
// {
//     std::vector<char*> res;
//     for (int i = 1; i < argc;   i++)
//     {
//         // peut etre fait dans le parsing en vrai
//         res.push_back(argv[i]);
//     }
//     _tab = res;
// }


std::vector<std::pair<int, int> > Merge::makePairs(std::vector<std::string> args)
{
    std::vector<std::pair<int, int> > pairs;

    if (args.size() % 2 != 0)
    {
        std::cout << "dans le cas impair\n";
        _leftover = atoi(args[args.size() - 1].c_str());
        _has_leftover = true;
        std::cout << "leftover => "<<_leftover << std::endl;
        for (size_t i = 0; i + 1 < args.size() - 1 ; i += 2)
        {
            int a = std::atoi(args[i].c_str());
            int b = std::atoi(args[i + 1].c_str());
            if(a > b)
                pairs.push_back(std::make_pair(b,a));
            else
                pairs.push_back(std::make_pair(a,b));
        }
    }
    else 
    {
        std::cout << "dans le cas pair\n";
        for (size_t i = 0; i + 1 < args.size() ; i += 2)
        {
           int a = std::atoi(args[i].c_str());
            int b = std::atoi(args[i + 1].c_str());
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
    std::vector<std::pair<int, int> >pairs = getPairs();

    
    for(size_t i = 0; i < pairs.size() ; i++)
        res.push_back(pairs[i].second);
    std::sort(res.begin(), res.end());
    std::cout << "BIGS\n";
    show_vector(res);
    _bigs = res;
}

void Merge::sort_smalls()
{
    std::vector<int> res;
    std::vector<std::pair<int, int> >pairs = getPairs();

    
    for(size_t i = 0; i < pairs.size() ; i++)
        res.push_back(pairs[i].first);
    std::sort(res.begin(), res.end());
    std::cout << "SMALLS\n";
    show_vector(res);
    _smalls = res;
}

std::vector<int> Merge::generateJacobSthal(int n)
{
    std::vector<int> res;

    res.push_back(0);
    res.push_back(1);
    int val = 1;
    while (val < n)
    {
        val = res[res.size() - 1] + 2 * res[res.size() - 2];
        res.push_back(val);
    }
    return (res);
}

void Merge::insert(std::vector<int>&vect, int val)
{
    if (std::find(vect.begin(), vect.end(), val) == vect.end())
    {
        std::vector<int>::iterator it = std::lower_bound(vect.begin(), vect.end(), val);
        vect.insert(it, val);
    }
}

void Merge::mergeInsert()
{
    std::vector<int> JacobSt = generateJacobSthal(_bigs.size());

    for (size_t i = 0; i < JacobSt.size() ; i ++)
    {
        size_t idx = JacobSt[i];
        if (idx < _bigs.size())
            insert(_smalls, _bigs[idx]);
    }
    if (_has_leftover == true)
        insert(_smalls, _leftover);
}

std::vector<int> Merge::getBigs() const
{
    return (this->_bigs);
}

std::vector<int> Merge::getSmalls() const
{
    return (this->_smalls);
}

