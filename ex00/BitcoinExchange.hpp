/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:18:01 by marwan            #+#    #+#             */
/*   Updated: 2025/12/12 16:42:56 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
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
        bool isValidDate(std::string date);
        float getValue(std::string date);
        void manage_inputfile(char *inputname);
};

#endif