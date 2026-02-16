/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:54:34 by marwan            #+#    #+#             */
/*   Updated: 2026/02/16 16:30:18 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <deque>


template <typename T>
void show_vector(std::vector<T> vect)
{
    for (size_t i =0; i < vect.size() ; i++)
        std::cout << "vect[ "<< i << "] =>" << vect[i] << std::endl;
}
template <typename Container>
Container split(const Container &args)
{
    Container res;

    std::stringstream ss(args[0]);
    std::string word;

    while (ss >> word)
        res.push_back(word);

    return res;
}

class PmergeMe
{
    private:
        std::vector<std::pair<int,int> > _pairs_vect;
		std::deque<std::pair<int,int> > _pairs_deque;
		template <typename Container>
		void insert(Container &c, int val)
		{
			if (std::find(c.begin(), c.end(), val) == c.end())
			{
				typename Container::iterator it = std::lower_bound(c.begin(), c.end(), val);
				c.insert(it, val);
			}
		}
        std::vector<char *> _tab;
        int _leftover;
        std::vector<int> _bigs_vect;
        std::vector<int> _smalls_vect;
		std::deque<int> _bigs_deque;
        std::deque<int> _smalls_deque;
        std::vector<int> _result;
		std::deque<int> _result_deque;
    public:
        bool _has_leftover;
        PmergeMe();
        ~PmergeMe();
        std::vector<std::pair<int, int> > makePairs_vect(std::vector<std::string> args);
		std::deque<std::pair<int, int> > makePairs_deque(std::deque<std::string> args);
        std::vector<std::pair<int, int> > getPairs_vect() const;
		std::deque<std::pair<int, int> > getPairs_deque() const;
        std::vector<int> getSmalls_vect() const;
		std::deque<int> getSmalls_deq() const;
        std::vector<int> getBigs_vect() const;
		std::deque<int> getBigs_deq() const;
		int getLeftover() const;
        void displayPairs();
		void displayPairs_deque();
        void sort_bigs_vect();
        void sort_smalls_vect();
		void sort_smalls_deque();
		void sort_bigs_deque();
        void mergeInsert();
		void mergeInsert_deque();
		template <typename Container>
		Container generateJacobSthal(int n)
		{
			Container res;

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
 
};

#endif

