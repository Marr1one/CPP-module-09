/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2026/02/17 21:43:17 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _has_leftover(false){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_leftover = other._leftover;
		this->_pairs_vect = other._pairs_vect;
		this->_pairs_deque = other._pairs_deque;
		this->_bigs_deque = other._bigs_deque;
		this->_bigs_vect = other._bigs_vect;
		this->_smalls_deque = other._smalls_deque;
		this->_smalls_vect = other._smalls_vect;
	}
	return (*this);
}

void PmergeMe::displayPairs()
{
    std::vector<std::pair<int,int> > pairs = getPairs_vect();
     for (size_t i = 0; i < pairs.size(); i ++)
        std::cout << "("  << pairs[i].first << ", " << pairs[i].second << ")\n";
}
void PmergeMe::displayPairs_deque()
{
    std::deque<std::pair<int,int> > pairs = getPairs_deque();
     for (size_t i = 0; i < pairs.size(); i ++)
        std::cout << "("  << pairs[i].first << ", " << pairs[i].second << ")\n";
}

std::vector<std::pair<int, int> > PmergeMe::getPairs_vect() const 
{
	return (this->_pairs_vect);
}

std::deque<std::pair<int, int> > PmergeMe::getPairs_deque() const 
{
	return (this->_pairs_deque);
}


std::vector<std::pair<int, int> > PmergeMe::makePairs_vect(std::vector<std::string> args)
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
	_pairs_vect = pairs;
	return (pairs);
}

std::deque<std::pair<int, int> > PmergeMe::makePairs_deque(std::deque<std::string> args)
{
	std::deque<std::pair<int, int> > pairs;

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
	_pairs_deque = pairs;
	return (pairs);
}

bool comparePairs(const std::pair<int, int> &a ,const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

void PmergeMe::sort_bigs_vect()
{
	std::vector<int> res;

	std::sort(_pairs_vect.begin(), _pairs_vect.end(), comparePairs);
	for(size_t i = 0; i < _pairs_vect.size() ; i++)
		res.push_back(_pairs_vect[i].second);
	_bigs_vect = res;
}


void PmergeMe::sort_smalls_vect()
{
	std::vector<int> res;
	
	for(size_t i = 0; i < _pairs_vect.size() ; i++)
		res.push_back(_pairs_vect[i].first);
	_smalls_vect = res;
}

void PmergeMe::sort_bigs_deque()
{
	std::deque<int> res;

	std::sort(_pairs_deque.begin(), _pairs_deque.end(), comparePairs);
	for(size_t i = 0; i < _pairs_deque.size() ; i++)
		res.push_back(_pairs_deque[i].second);
	_bigs_deque = res;
}


void PmergeMe::sort_smalls_deque()
{
	std::deque<int> res;

	for(size_t i = 0; i < _pairs_deque.size() ; i++)
		res.push_back(_pairs_deque[i].first);
	_smalls_deque = res;
}


void PmergeMe::mergeInsert()
{
	std::vector<bool> inserted (this->_smalls_vect.size(), false);
	std::vector<int>res=_bigs_vect;
	std::vector<int> JacobSt = generateJacobSthal<std::vector<int> >(_smalls_vect.size());
	for (size_t i = 0; i < JacobSt.size() ; i ++)
	{
		size_t idx = JacobSt[i];
		if (idx < _smalls_vect.size() && !inserted[idx])
		{
			insertBounded(res, idx);
			inserted[idx]=true;
		}
	}
	for(size_t i =0; i < _smalls_vect.size();i++)
	{
		if (!inserted[i])
			insertBounded(res, i);
	}
	if (_has_leftover == true)
		insertLeftover(res, _leftover);
	_smalls_vect =res;
}


// void PmergeMe::mergeInsert_deque()
// {
// 	std::deque<int>res=_bigs_deque;
// 	std::deque<int> JacobSt = generateJacobSthal<std::deque<int> >(_smalls_deque.size());
// 	for (size_t i = 0; i < JacobSt.size() ;i++)
// 	{
// 		size_t idx = JacobSt[i];
// 		if (idx < _smalls_deque.size())
// 			insert(res, _smalls_deque[idx]);
// 	}
// 	for(size_t i =0; i < _smalls_deque.size();i++)
// 		insert(res,_smalls_deque[i]);
// 	if (_has_leftover == true)
// 		insert(res, _leftover);
// 	_smalls_deque =res;
// }

std::vector<int> PmergeMe::getBigs_vect() const
{
	return (this->_bigs_vect);
}

std::vector<int> PmergeMe::getSmalls_vect() const
{
	return (this->_smalls_vect);
}

std::deque<int> PmergeMe::getBigs_deq() const
{
	return (this->_bigs_deque);
}

std::deque<int> PmergeMe::getSmalls_deq() const
{
	return (this->_smalls_deque);
}

std::vector<int> PmergeMe::get_result() const
{
	return (this->_result);
}

int PmergeMe::getLeftover() const
{
	return this->_leftover;
}
