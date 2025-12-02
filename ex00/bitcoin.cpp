/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoin.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:20:02 by marwan            #+#    #+#             */
/*   Updated: 2025/11/25 21:39:33 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoin.hpp"

Bitcoin::Bitcoin(){};

Bitcoin::~Bitcoin(){};

bool Bitcoin::fill_database()
{
    std::ifstream file("data.csv");

    if (!file.is_open())
        return (false);
    std::string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        std::string value = line.substr(comma + 1);
        float f_value = atof(value.c_str());
        _database[date] = f_value;
    }
    file.close();
    return (true);
}

void Bitcoin::display_database()
{
    std::map<std::string, float>::iterator it;
    for (it = _database.begin(); it != _database.end() ; it++)
        std::cout << it->first << "|" << it->second << "\n";
}

bool Bitcoin::isValidDate(std::string date)
{
    size_t minus = date.find('-');
    if (minus == std::string::npos)
        return (false);
    std::string year = date.substr(0, minus);
    int i_year = atoi(year.c_str());
    if (i_year < 2010 || i_year > 2022)
        return (false);
    size_t save_minus = minus;
    minus = date.find('-');
    if (minus == std::string::npos)
        return (false);
    std::string month = date.substr(save_minus + 1, minus);
    int i_month = atoi(month.c_str());
    if (i_month < 1 || i_month > 12)
        return (false);
    std::string day = date.substr(minus + 1);
    int i_day = atoi(day.c_str());
    if (i_day < 1 || i_day > 30)
        return (false);
    return (true);
}

void Bitcoin::manage_inputfile(char *inputname)
{
    std::string line;
    std::ifstream inputfile(inputname);

    getline(inputfile, line);
    while (getline(inputfile, line))
    {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipe);
        if (!isValidDate(date))
        {
            std::cout << "Error : date not valid\n";
            continue;
        }
        std::string amount = line.substr(pipe + 1);
        float f_value = atof(amount.c_str());
        if (f_value  < 0)
        {
            std::cout << "Error : not a positive number\n";
            continue;
        }
        if (f_value > 100000)
        {
            std::cout << "Error : Amount too large\n";
            continue;
        }
        float valuecsv = getValue(date);
        float res = f_value * valuecsv;
        std::cout << line << " => " <<  res << std::endl;
    }
}

float Bitcoin::getValue(std::string date)
{
    std::map<std::string, float>::iterator it;
    it = _database.find(date);
    if (it != _database.end())
        return it->second;
    it = _database.lower_bound(date);
    return it->second;
}
