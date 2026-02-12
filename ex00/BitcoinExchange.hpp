/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:18:01 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 18:26:07 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include "limits.h"

class BitcoinExchange
{
    private :
        std::map<std::string, float> _database;
    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &other);
        BitcoinExchange &operator=(BitcoinExchange const &other);
        ~BitcoinExchange();
        bool fill_database();
        void display_database();
        bool isValidDate(const std::string &date);
        float getValue(const std::string &date) const;
        void manage_inputfile(char *inputname);
};

#endif