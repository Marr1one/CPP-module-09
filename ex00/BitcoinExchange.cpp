/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:20:02 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 17:01:52 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_database = other._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){};

bool BitcoinExchange::fill_database()
{
    std::ifstream file("data.csv"); 

    if (!file.is_open())
        return (false);
    std::string line;
    getline(file, line);
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

void BitcoinExchange::display_database()
{
    std::map<std::string, float>::iterator it;
    for (it = _database.begin(); it != _database.end() ; it++)
        std::cout << it->first << "|" << it->second << "\n";
}

bool ValidAmount(const std::string &str)
{	
	int dot = 0;
	for(int i = 0;i < str.size();i++)
	{
		if (str[i] == '.' && i != 0 && dot==0)
			continue;
		if (str[i] == '.' && dot==1)
			return (false);
		if (!isdigit(str[i])) return (false);

	}
	return (true);
}

bool ValidNumber(const std::string &str)
{
	for(int i = 0;i < str.size();i++)
		if (!isdigit(str[i])) return (false);
	return (true);
}

std::string trimSpace(std::string &str)
{
	std::string res;
	for(int i = 0; i<str.size(); i++)
		if (str[i] != ' ' && str[i] != '\t')res.push_back(str[i]);
	return (res);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    size_t minus = date.find('-');
    if (minus == std::string::npos)
        return (false);
    std::string year = date.substr(0, minus);
	if (!ValidNumber(year)) return false;
    int i_year = atoi(year.c_str());
    if (i_year < 2010 || i_year > 2022)
        return (false);
    size_t save_minus = minus;
    minus = date.find('-', save_minus + 1);
    if (minus == std::string::npos)
        return (false);
    std::string month = date.substr(save_minus + 1, 2);
	if (!ValidNumber(month)) return false;
    int i_month = atoi(month.c_str());
    if (i_month < 1 || i_month > 12)
        return (false);
    std::string day = date.substr(minus + 1);
	day = trimSpace(day);
	if (!ValidNumber(day)) return false;
    int i_day = atoi(day.c_str());//peut etre faire un isdigit pour verifier les 3205dd
    if ((i_month == 2 && i_day > 29) || i_day < 1 || i_day > 31)
        return (false);
    return (true);
}

void BitcoinExchange::manage_inputfile(char *inputname)
{
    std::string line;
    std::ifstream inputfile(inputname);
    if (!inputfile.is_open())
    {
        std::cout << "Error: couldn't open the input file\n";
        return;
    }
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
            std::cout << "Error: bad input = > " << date  << std::endl;
            continue;
        }
        std::string amount = line.substr(pipe + 1);
		std::string trimmedAmount = trimSpace(amount);
		if (!ValidAmount(trimmedAmount))
		{
			std::cout << "Error: bad amount value = > " << amount << std::endl;
			continue; 
		}
        float f_value = atof(amount.c_str());
        if (f_value  < 0)
        {
            std::cout << "Error : not a positive number\n";
            continue;
        }
        if (f_value > 1000)
        {
            std::cout << "Error : Amount too large\n";
            continue;
        }
        float valuecsv = getValue(date);
        float res = f_value * valuecsv;
        std::cout << line << " => " <<  res << std::endl;
    }
}

float BitcoinExchange::getValue(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it;
    it = _database.find(date);
    if (it != _database.end())
        return it->second;
    it = _database.lower_bound(date);
    if (it == _database.begin())
        return it->second;
    if (it == _database.end())
        it--;
    return it->second;
}
