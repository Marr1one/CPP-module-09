/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:03:33 by marwan            #+#    #+#             */
/*   Updated: 2026/01/28 16:59:06 by marwan           ###   ########.fr       */
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
        void displayExpr();
        std::string trimExpr();
        std::string getExpression() const;
        bool checkChars();
        int calculate();
        private:
            std::string _expression;
};