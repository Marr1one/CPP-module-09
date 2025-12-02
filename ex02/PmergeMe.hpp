/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:54:34 by marwan            #+#    #+#             */
/*   Updated: 2025/11/30 18:06:16 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void show_vector(std::vector<T> vect)
{
    for (int i =0; i < vect.size() ; i++)
    {
        std::cout << "vect[ "<< i << "] =>" << vect[i] << std::endl;
    }
}

class Merge 
{
    public:
        Merge();
        ~Merge();
        std::vector<std::pair<int, int>> makePairs(int argc, char *argv[]);
        std::vector<std::pair<int, int>> getPairs();
        std::vector<char*> getTab();
        void makeTab(int argc, char **argv);
        void displayPairs();
        void displayTab();
        void sort_bigs();
        void sort_smalls();
    private:
        std::vector<std::pair<int, int>> _pairs;
        std::vector<char *> _tab;
        int _leftover;
        std::vector<int> _bigs;
        std::vector<int> _smalls;
};