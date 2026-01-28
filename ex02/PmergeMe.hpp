/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:54:34 by marwan            #+#    #+#             */
/*   Updated: 2026/01/28 17:22:32 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


template <typename T>
void show_vector(std::vector<T> vect)
{
    for (int i =0; i < vect.size() ; i++)
        std::cout << "vect[ "<< i << "] =>" << vect[i] << std::endl;
}

std::vector<std::string> split(std::vector<std::string> args, char c);

class Merge 
{
    private:
        std::vector<std::pair<int, int>> _pairs;
        void insert(std::vector<int>&vect, int val);
        std::vector<char *> _tab;
        int _leftover;
        bool _has_leftover;
        std::vector<int> _bigs;
        std::vector<int> _smalls;
        std::vector<int> _result;
    public:
        Merge();
        ~Merge();
        std::vector<std::pair<int, int>> makePairs(std::vector<std::string> args);
        std::vector<std::pair<int, int>> getPairs() const;
        std::vector<int> getSmalls() const;
        std::vector<int> getBigs() const;
        void displayPairs();
        void sort_bigs();
        void sort_smalls();
        void mergeInsert();
        std::vector<int> generateJacobSthal(int n);
 
};