/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:41:12 by marwan            #+#    #+#             */
/*   Updated: 2026/03/04 14:31:09 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage => ./RPN \"expression\"\n", 1);
    try
    {
        RPN expr(argv[1]);
        int res = expr.calculate();
        std::cout<< res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
    return (0);
}