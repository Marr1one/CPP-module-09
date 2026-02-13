/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2026/02/13 17:39:46 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

MergeVector::MergeVector() : _has_leftover(false){};

MergeVector::~MergeVector(){};


std::vector<std::string> split(std::vector<std::string> args)
{
    std::vector<std::string> res;
    std::stringstream ss(args[0]);
    std::string word;
    while (ss >> word)
        res.push_back(word);
    return (res);
}


void MergeVector::displayPairs()
{
    std::vector<std::pair<int,int> > pairs = getPairs();
     for (size_t i = 0; i < pairs.size(); i ++)
        std::cout << "("  << pairs[i].first << ", " << pairs[i].second << ")\n";
}

std::vector<std::pair<int, int> > MergeVector::getPairs() const 
{
	return (this->_pairs);
}


std::vector<std::pair<int, int> > MergeVector::makePairs(std::vector<std::string> args)
{
	std::vector<std::pair<int, int> > pairs;

	if (args.size() % 2 != 0)
	{
		_leftover = atoi(args[args.size() - 1].c_str());
		_has_leftover = true;
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

bool comparePairs(const std::pair<int, int> &a ,const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

void MergeVector::sort_bigs()
{
	std::vector<int> res;

	std::sort(_pairs.begin(), _pairs.end(), comparePairs);
	for(size_t i = 0; i < _pairs.size() ; i++)
		res.push_back(_pairs[i].second);
	_bigs = res;
}

void MergeVector::sort_smalls()
{
	std::vector<int> res;

	for(size_t i = 0; i < _pairs.size() ; i++)
		res.push_back(_pairs[i].first);
	_smalls = res;
}

std::vector<int> MergeVector::generateJacobSthal(int n)
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

void MergeVector::insert(std::vector<int>&vect, int val)
{
	if (std::find(vect.begin(), vect.end(), val) == vect.end())
	{
		std::vector<int>::iterator it = std::lower_bound(vect.begin(), vect.end(), val);
		vect.insert(it, val);
	}
}

void MergeVector::mergeInsert()
{
	std::vector<int>res=_bigs;
	std::vector<int> JacobSt = generateJacobSthal(_smalls.size());
	for (size_t i = 0; i < JacobSt.size() ; i ++)
	{
		size_t idx = JacobSt[i];
		if (idx < _bigs.size())
			insert(res, _smalls[idx]);
	}
	for(size_t i =0; i < _smalls.size();i++)
		insert(res,_smalls[i]);
	if (_has_leftover == true)
		insert(res, _leftover);
	_smalls =res;
}

std::vector<int> MergeVector::getBigs() const
{
	return (this->_bigs);
}

std::vector<int> MergeVector::getSmalls() const
{
	return (this->_smalls);
}

