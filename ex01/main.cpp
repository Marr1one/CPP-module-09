/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:41:12 by marwan            #+#    #+#             */
/*   Updated: 2025/11/27 17:48:56 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage => ./RPN \"expression\"\n";
        return (1);
    }
    
    try
    {
        RPN expr(argv[1]);
        expr.displayExpr();
        int res = expr.calculate();
        std::cout << "resultat => " << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
   
    
    return (0);
}