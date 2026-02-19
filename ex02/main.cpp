/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:53:33 by marwan            #+#    #+#             */
/*   Updated: 2026/02/19 14:54:41 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isNumberString(std::string str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i])&& !isspace(str[i]))
        {
            std::cout << "DEBUG str[i] => {" << str[i] << "}\n";
            return (false);
        }
    }
    return (true);
}

//bool parser_vector(std::vector<std::string> vect)
//{
//    for(size_t i = 0; i < vect.size() ; i++)
//    {
//        if (!isNumberString(vect[i]))
//        {
//            std::cout << "DEBUG  argv[i] => {" << vect[i] << "}\n";
//            return (false);
//        }
//    }
//    return (true);
//}

template <typename Container>

bool parser(const Container &c)
{
    for(size_t i = 0; i < c.size() ; i++)
    {
        if (!isNumberString(c[i]))
        {
            std::cout << "DEBUG  argv[i] => {" << c[i] << "}\n";
            return (false);
        }
    }
    return (true);
}

template <typename Container>
Container argv_to_string(int argc, char **argv)
{
	Container res;
	for(int i = 1;i < argc;i++)
	{
		std::stringstream ss(argv[i]);
		std::string token;
		while(ss >> token)
			res.push_back(token);
	}
	return (res);
}

template<typename Container>
void cleanshow(const Container& c)
{
	for(size_t i = 0;i <c.size();i++)
	{
		std::cout <<c[i];
		if (i+1<c.size())std::cout <<" ";
	}
	std::cout << std::endl;
}


template<typename Container>
bool detect_duplicate(const Container &v)
{
	for(size_t i = 0;i < v.size();i++)
	{
		for(size_t j=i+1;j<v.size();j++)
		{
			if (v[j]==v[i])
				return (false);
		}
	}
	return (true);
}

bool checkMaxs(std::vector<std::string>v)
{
	for(size_t i=0;i < v.size();i++)
	{
		long num=atol(v[i].c_str());
		if (num > INT_MAX || num < INT_MIN)return (false);
	}
	return (true);
}



int main(int argc, char **argv)
{
	
	std::cout << "--------------TRI UTILISANT VECTOR---------------\n";
	
    if (argc < 2) return (std::cerr << "Error: not enough args\n", 1);
    std::vector<std::string> args_vec = argv_to_string<std::vector<std::string> >(argc ,argv);
	if (!detect_duplicate<std::vector<std::string> >(args_vec)) return (std::cerr << "Error: duplicate detected !\n",1);
    if (!parser(args_vec)) return (std::cerr << "Error: invalid inputs\n", 1);
	if (!checkMaxs(args_vec)) return (std::cerr << "Error: int max or min detecteds\n", 1);
    PmergeMe m;
	std::cout <<"Before :";
	cleanshow<std::vector<std::string> >(args_vec);
	clock_t start = std::clock();
    m.makePairs_vect(args_vec);
    m.sort_bigs_vect();
    m.sort_smalls_vect();
    m.mergeInsert();
	clock_t end = std::clock();
	double time = static_cast<double>(end-start) / CLOCKS_PER_SEC * 1000000;
	std::cout <<"After :";
	cleanshow(m.getSmalls_vect());
	std::cout << "Time to process a range of "
		<< args_vec.size() << " elements with std::vector :"
		<< time << " us" << std::endl;
	std::cout << "---------------TRI UTILISANT DEQUE---------------\n";
	std::deque<std::string> args_deque = argv_to_string<std::deque<std::string> >(argc ,argv);
    PmergeMe mdeque;
	std::cout <<"Before :";
	cleanshow<std::deque<std::string> >(args_deque);
	clock_t start_deque = std::clock();
    mdeque.makePairs_deque(args_deque);
    mdeque.sort_bigs_deque();
    mdeque.sort_smalls_deque();
    mdeque.mergeInsert_deque();
	clock_t end_deque = std::clock();
	double time_deque = static_cast<double>(end_deque-start_deque) / CLOCKS_PER_SEC * 1000000;
	std::cout <<"After :";
	cleanshow(mdeque.getSmalls_deq());
	std::cout << "Time to process a range of "
		<< args_deque.size() << " elements with std::deque :"
		<< time_deque << " us" << std::endl;
    return (0);
}