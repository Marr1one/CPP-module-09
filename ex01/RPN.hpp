/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:03:33 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 18:00:40 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
    public:
        RPN(std::string expression);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        void displayExpr() const;
        std::string getExpression() const;
        bool checkChars();
		bool checkExpr();
        int calculate();
    private:
		std::string _expression;
		std::string trimExpr();
};