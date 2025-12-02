/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:04:39 by marwan            #+#    #+#             */
/*   Updated: 2025/11/29 14:46:25 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression)
{
    _expression = expression;
}

RPN::~RPN(){}

std::string RPN::getExpression()
{
    return (_expression);
}

void RPN::displayExpr()
{
    std::cout << "expression => " << getExpression() << std::endl;
}

std::string RPN::trimExpr()
{
    std::string original = getExpression();
    std::string trim;
    int i = 0;
    while (i < original.length())
    {
        if (original[i] != ' ')
            trim.push_back(original[i]);
        i++;
    }
    std::cout << "original => " << original << std::endl;
    std::cout << "trimmed => " << trim << std::endl;
    return (trim);
}

bool RPN::checkChars()
{
    std::string trimmed = this->trimExpr();
    for(int i = 0; i < trimmed.length() ; i++)
    {
        if (trimmed[i] < '0' || trimmed[i] > '9')
        {
            if(trimmed[i] != '+' && trimmed[i] != '*' && trimmed[i] != '/' && trimmed[i] != '-')
                return (false);
        }
    }
    return (true);
}

bool isNum(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool isOperator(char c)
{
    if(c != '+' && c != '*' && c != '/' && c != '-')
                return (false);
    return (true);
}

int doOp(int a,int b, char c)
{
    if (c == '+')
        return (a + b);
    if (c == '-')
        return (a - b);
    if (c == '*')
        return (a * b);
    return (a / b);
}

int RPN::calculate()
{
    if (!checkChars())
        throw std::runtime_error("Error invalid char");
    std::stack<int> st;
    std::string expr = trimExpr();
    int a,b;

    for(int i = 0 ; i < expr.length(); i++)
    {
        if (isNum(expr[i]))
            st.push(expr[i] - '0');
        if (isOperator(expr[i]))
        {
            if (st.size() < 2)
                throw std::runtime_error("Error size < 2\n");
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            int res = doOp(a,b, expr[i]);
            st.push(res);     
        }
    }
    return (st.top());
}

//1 recuperer lexpression
// 2 enlever les espaces
// 3 parser que des chiffres et operatations
// faire les fonctions pour les operations !
// 4 faire le calcule: stocker les chiffres
// deux chiffres max peuvent etre stocke