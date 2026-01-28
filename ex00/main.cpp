/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:00:26 by marwan            #+#    #+#             */
/*   Updated: 2026/01/25 21:13:59 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"



int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage => ./btc inputfile\n", 1);
    BitcoinExchange base;
    if (!base.fill_database()) return (std::cout << "Impossible to open database !\n", 1);
    base.manage_inputfile(argv[1]);
    
    return (0);
}
