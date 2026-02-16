/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2026/02/16 16:39:33 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _has_leftover(false){};

PmergeMe::~PmergeMe(){};


//std::vector<std::string> split(std::vector<std::string> args)
//{
//    std::vector<std::string> res;
//    std::stringstream ss(args[0]);
//    std::string word;
//    while (ss >> word)
//        res.push_back(word);
//    return (res);
//}

//template <typename Container>
//Container split(const Container& args)
//{
//    Container res;

//    std::stringstream ss(args[0]);
//    std::string word;

//    while (ss >> word)
//        res.push_back(word);

//    return (res);
//}

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


//std::vector<int> PmergeMe::generateJacobSthal(int n)
//{
//	std::vector<int> res;

//	res.push_back(0);
//	res.push_back(1);
//	int val = 1;
//	while (val < n)
//	{
//		val = res[res.size() - 1] + 2 * res[res.size() - 2];
//		res.push_back(val);
//	}
//	return (res);
//}
//template <typename Container>
//Container PmergeMe::generateJacobSthal(int n)
//{
//	Container res;

//	res.push_back(0);
//	res.push_back(1);
//	int val = 1;
//	while (val < n)
//	{
//		val = res[res.size() - 1] + 2 * res[res.size() - 2];
//		res.push_back(val);
//	}
//	return (res);
//}


//template <typename Container>
//void PmergeMe::insert(Container &vect, int val)
//{
//	if (std::find(vect.begin(), vect.end(), val) == vect.end())
//	{
//		typename Container::iterator it = std::lower_bound(vect.begin(), vect.end(), val);
//		vect.insert(it, val);
//	}
//}

void PmergeMe::mergeInsert()
{
	std::vector<int>res=_bigs_vect;
	std::vector<int> JacobSt = generateJacobSthal<std::vector<int> >(_smalls_vect.size());
	for (size_t i = 0; i < JacobSt.size() ; i ++)
	{
		size_t idx = JacobSt[i];
		if (idx < _bigs_vect.size())
			insert(res, _smalls_vect[idx]);
	}
	for(size_t i =0; i < _smalls_vect.size();i++)
		insert(res,_smalls_vect[i]);
	if (_has_leftover == true)
		insert(res, _leftover);
	_smalls_vect =res;
}

void PmergeMe::mergeInsert_deque()
{
	std::deque<int>res=_bigs_deque;
	std::deque<int> JacobSt = generateJacobSthal<std::deque<int> >(_smalls_deque.size());
	for (size_t i = 0; i < JacobSt.size() ; i ++)
	{
		size_t idx = JacobSt[i];
		if (idx < _bigs_deque.size())
			insert(res, _smalls_deque[idx]);
	}
	for(size_t i =0; i < _smalls_deque.size();i++)
		insert(res,_smalls_deque[i]);
	if (_has_leftover == true)
		insert(res, _leftover);
	_smalls_deque =res;
}

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

int PmergeMe::getLeftover() const
{
	return this->_leftover;
}
