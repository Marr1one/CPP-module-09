/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:00:26 by marwan            #+#    #+#             */
/*   Updated: 2025/11/25 18:03:46 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bitcoin.hpp"



int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Usage => ./btc inputfile\n", 1);

    Bitcoin base;
    base.fill_database();

    base.manage_inputfile(argv[1]);
    
    return (0);
}
