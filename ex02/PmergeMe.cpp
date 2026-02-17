/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:55:18 by marwan            #+#    #+#             */
/*   Updated: 2026/02/17 17:31:34 by maissat          ###   ########.fr       */
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


//template <typename Container>
//void PmergeMe::insert(Container &vect, int val)
//{
//	if (std::find(vect.begin(), vect.end(), val) == vect.end())
//	{
//		typename Container::iterator it = std::lower_bound(vect.begin(), vect.end(), val);
//		vect.insert(it, val);
//	}
//}

//void PmergeMe::mergeInsert()
//{
//	std::vector<int>res=_bigs_vect;
//	std::vector<int> JacobSt = generateJacobSthal<std::vector<int> >(_smalls_vect.size());
//	for (size_t i = 0; i < JacobSt.size() ; i ++)
//	{
//		size_t idx = JacobSt[i];
//		if (idx < _smalls_vect.size())
//			insert(res, _smalls_vect[idx]);
//	}
//	for(size_t i =0; i < _smalls_vect.size();i++)
//		insert(res,_smalls_vect[i]);
//	if (_has_leftover == true)
//		insert(res, _leftover);
//	_smalls_vect =res;
//}

std::vector<size_t> PmergeMe::buildInsertOrder(size_t n)
{
    std::vector<size_t> order;
    if (n <= 1) return order; // small[0] déjà inséré

    std::vector<size_t> jacob = generateJacobSthal<std::vector<size_t> >(n);

    size_t prev = 1;
    for (size_t k = 1; k < jacob.size(); k++)
    {
        size_t curr = jacob[k];
        // Dans chaque groupe, on insère de curr vers prev+1 (décroissant)
        size_t idx = (curr < n) ? curr : n - 1;
        while (idx > prev)
        {
            order.push_back(idx);
            idx--;
        }
        prev = jacob[k];
    }
    return order;
}

void PmergeMe::mergeInsert()
{
    // _bigs_vect est déjà trié récursivement
    // _smalls_vect[i] <= _bigs_vect[i] pour chaque paire
     std::cout << "bigs: ";
    for (size_t i = 0; i < _bigs_vect.size(); i++) std::cout << _bigs_vect[i] << " ";
    std::cout << std::endl;
    std::cout << "smalls: ";
    for (size_t i = 0; i < _smalls_vect.size(); i++) std::cout << _smalls_vect[i] << " ";
    std::cout << std::endl;
    std::cout << "order: ";
    std::vector<size_t> order = buildInsertOrder(_smalls_vect.size());
    for (size_t i = 0; i < order.size(); i++) std::cout << order[i] << " ";
    std::cout << std::endl;
    std::vector<int> res = _bigs_vect;

    // Étape 1 : small[0] est garanti <= big[0], on l'insère en tête
    if (!_smalls_vect.empty())
        res.insert(res.begin(), _smalls_vect[0]);

    // Étape 2 : ordre d'insertion Jacobsthal pour les smalls restants
    std::vector<size_t> order2 = buildInsertOrder(_smalls_vect.size());

    for (size_t k = 0; k < order2.size(); k++)
    {
        size_t idx = order2[k];
        if (idx >= _smalls_vect.size())
            continue;

        int val = _smalls_vect[idx];

        // Le pendant big[idx] est dans res — on le trouve pour borner la recherche
        // Après insertions précédentes, big[idx] = _bigs_vect[idx] est quelque part dans res
        // On cherche sa position pour borner le lower_bound
        std::vector<int>::iterator bound = std::find(res.begin(), res.end(), _bigs_vect[idx]);
        // bound pointe sur big[idx] : on cherche val uniquement dans [begin, bound]
        
        std::vector<int>::iterator it = std::lower_bound(res.begin(), bound, val);
        res.insert(it, val);
    }

    // Étape 3 : leftover (élément impair non apparié)
    if (_has_leftover)
    {
        std::vector<int>::iterator it =
            std::lower_bound(res.begin(), res.end(), _leftover);
        res.insert(it, _leftover);
    }

    _result = res;
}

void PmergeMe::mergeInsert_deque()
{
	std::deque<int>res=_bigs_deque;
	std::deque<int> JacobSt = generateJacobSthal<std::deque<int> >(_smalls_deque.size());
	for (size_t i = 0; i < JacobSt.size() ;i++)
	{
		size_t idx = JacobSt[i];
		if (idx < _smalls_deque.size())
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

std::vector<int> PmergeMe::get_result() const
{
	return (this->_result);
}

int PmergeMe::getLeftover() const
{
	return this->_leftover;
}
