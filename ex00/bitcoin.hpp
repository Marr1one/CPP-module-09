/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:18:01 by marwan            #+#    #+#             */
/*   Updated: 2025/11/25 18:04:42 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <fstream>
#include "limits.h"

class Bitcoin 
{
    public :
        Bitcoin();
        ~Bitcoin();
        bool fill_database();
        void display_database();
        bool isValidDate(std::string date);
        float getValue(std::string date);
        void manage_inputfile(char *inputname);
    private :
        std::map<std::string, float> _database;
};