/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:04:39 by marwan            #+#    #+#             */
/*   Updated: 2026/02/12 18:34:29 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression)
{
    _expression = expression;
}

RPN::~RPN(){}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_expression = other._expression;
    }
    return (*this);
}

std::string RPN::getExpression() const
{
    return (_expression);
}

void RPN::displayExpr() const
{
    std::cout << "expression => " << getExpression() << std::endl;
}

std::string RPN::trimExpr()
{
    std::string original = getExpression();
    std::string trim;
    for(size_t i = 0; i < original.size(); i++)
        if (original[i] != ' ' && original[i] != '\t') trim.push_back(original[i]);
    return (trim);
}

bool RPN::checkChars()
{
    const std::string trimmed = this->trimExpr();
    std::string valid = "0123456789+-*/";
    for(size_t i = 0; i < trimmed.length() ; i++)
        if (valid.find(trimmed[i]) == std::string::npos) return (false);
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
    if (c == '+') return (a + b);
    else if (c == '-') return (a - b);
    else if (c == '*') return (a * b);
    else return (a / b);
}

int countOp(std::string expr)
{
	int count = 0;
	for(size_t i=0;i <expr.size();i++)
		if (isOperator(expr[i]))count++;
	return (count);
}
int countDigit(std::string expr)
{
	int count = 0;
	for(size_t i=0;i <expr.size();i++)
		if (isdigit(expr[i]))count++;
	return (count);
}

bool RPN::checkExpr()
{
	int nbOp = countOp(this->_expression);
	int nbDigit = countDigit(this->_expression);
	if (nbOp==0)return (false);
	else if (nbOp != nbDigit - 1) return (false);
	else return (true);
}
	

int RPN::calculate()
{
    if (!checkChars())
        throw std::runtime_error("Error: invalid char");
	else if(!checkExpr())
		throw std::runtime_error("Error: invalid expression");
    std::stack<int> st;
    std::string trimmedExpr = trimExpr();
    int a,b;
    for(size_t i = 0 ; i < trimmedExpr.size(); i++)
    {
        if (isNum(trimmedExpr[i]))
            st.push(trimmedExpr[i] - '0');
        else if (isOperator(trimmedExpr[i]))
        {
            if (st.size() < 2) throw std::runtime_error("Error size  < 2\n");
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            int res = doOp(a,b, trimmedExpr[i]);
            st.push(res);     
        }
    }
    return (st.top());
}