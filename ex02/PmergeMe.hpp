/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:54:34 by marwan            #+#    #+#             */
/*   Updated: 2026/02/20 16:01:02 by maissat          ###   ########.fr       */
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
#include <climits>


template <typename T>
void show_vector(std::vector<T> vect)
{
    for (size_t i =0; i < vect.size() ; i++)
        std::cout << "vect[ "<< i << "] =>" << vect[i] << std::endl;
}

class PmergeMe
{
    private:
        std::vector<std::pair<int,int> > _pairs_vect;
		std::deque<std::pair<int,int> > _pairs_deque;
		template <typename Container>
		void insertLeftover(Container &c, int leftover)
		{
			//if (std::find(c.begin(), c.end(), leftover) == c.end())
			//{
				typename Container::iterator it = std::lower_bound(c.begin(), c.end(), leftover);
				c.insert(it, leftover);
			//}
		}
		void insertBounded(std::vector<int> &c, size_t idx);
		void insertBounded_deque(std::deque<int> &c, size_t idx);
        int _leftover;
        std::vector<int> _bigs_vect;
        std::vector<int> _smalls_vect;
		std::deque<int> _bigs_deque;
        std::deque<int> _smalls_deque;
    public:
        bool _has_leftover;
        PmergeMe();
        ~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
        std::vector<std::pair<int, int> > makePairs_vect(std::vector<std::string> args);
		std::deque<std::pair<int, int> > makePairs_deque(std::deque<std::string> args);
        void sort_pairs_vect();
        void create_smalls_vect();
		void create_smalls_deque();
		void sort_pairs_deque();
        void mergeInsert();
		void mergeInsert_deque();
        std::vector<std::pair<int, int> > getPairs_vect() const;
		std::deque<std::pair<int, int> > getPairs_deque() const;
        std::vector<int> getSmalls_vect() const;
		std::deque<int> getSmalls_deq() const;
        std::vector<int> getBigs_vect() const;
		std::deque<int> getBigs_deq() const;
		int getLeftover() const;
        //void displayPairs(); //utile au cas ou pour voir les pairs ! 
		//void displayPairs_deque();
		template <typename Container>
		Container generateJacobSthal(size_t n)
		{
			Container res;

			res.push_back(0);
			res.push_back(1);
			size_t val = 1;
			while (val < n)
			{
				val = res[res.size() - 1] + 2 * res[res.size() - 2];
				res.push_back(val);
			}
			return (res);
		}
 
};

#endif

