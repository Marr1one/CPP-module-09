/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:53:33 by marwan            #+#    #+#             */
/*   Updated: 2026/02/16 16:41:46 by maissat          ###   ########.fr       */
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
//std::vector<std::string> argv_to_string(int argc ,char **argv)
//{
//    std::vector<std::string> res;
//    for(int i = 1; i < argc ; i++ )
//        res.push_back(argv[i]);
//    return (res);
//}

template <typename Container>
Container argv_to_string(int argc ,char **argv)
{
    Container res;
    for(int i = 1; i < argc ; i++ )
        res.push_back(argv[i]);
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
//--------------------------------------------____FAUT QUE JE RETURN SI JE DETECTE DOUBLON----------------------------------
int main(int argc, char **argv)
{

	std::cout << "--------------TRI UTILISANT VECTOR---------------\n";
    if (argc < 2)
        return (std::cerr << "Error\n not enough args\n", 1);
    std::vector<std::string> args_vec = argv_to_string<std::vector<std::string> >(argc ,argv);
    if (argc == 2)
    {
        std::vector<std::string> splitted;
        splitted = split(args_vec);
        std::cout << "after split\n";
        //show_vector(splitted);
        args_vec = splitted;
    }
    if (!parser(args_vec))
        return (std::cerr << "Invalid inputs\n", 1);
    PmergeMe m;
	std::cout <<"Before :";
	cleanshow<std::vector<std::string> >(args_vec);
	clock_t start = std::clock();
    m.makePairs_vect(args_vec);
    //m.displayPairs();
    m.sort_smalls_vect();
    m.sort_bigs_vect();
    m.mergeInsert();
    //std::cout << "smalls after merge insert\n";
    //show_vector(m.getSmalls());
	clock_t end = std::clock();
	double time = static_cast<double>(end-start) / CLOCKS_PER_SEC * 1000000;
	std::cout <<"After :";
	cleanshow(m.getSmalls_vect());
	std::cout << "Time to process a range of "
		<< args_vec.size() << " elements with std::vector :"
		<< time << " us" << std::endl;
	std::cout << "---------------TRI UTILISANT DEQUE---------------\n";
	std::deque<std::string> args_deque = argv_to_string<std::deque<std::string> >(argc ,argv);
	if (argc == 2)
    {
        std::deque<std::string> splitted;
        splitted = split<std::deque<std::string> >(args_deque);
        std::cout << "after split\n";
        //show_vector(splitted);
        args_deque = splitted;
    }
	if (!parser(args_deque))
        return (std::cerr << "Invalid inputs\n", 1);
    PmergeMe mdeque;
	std::cout <<"Before :";
	cleanshow<std::deque<std::string> >(args_deque);
	clock_t start_deque = std::clock();
	//for(size_t i = 0; i < args_deque.size();i++)
	//{
	//	std::cout << args_deque[i] << std::endl;
	//}
    mdeque.makePairs_deque(args_deque);
    //mdeque.displayPairs_deque();
	//if (mdeque._has_leftover)std::cout << "leftover = > " << mdeque.getLeftover() << std::endl;
    mdeque.sort_smalls_deque();
    mdeque.sort_bigs_deque();
	//std::cout << "DEBUG\n" << std::endl;
    mdeque.mergeInsert_deque();
    //std::cout << "smalls after merge insert\n";
    //show_vector(m.getSmalls());
	clock_t end_deque = std::clock();
	double time_deque = static_cast<double>(end_deque-start_deque) / CLOCKS_PER_SEC * 1000000;
	std::cout <<"After :";
	cleanshow(mdeque.getSmalls_deq());
	std::cout << "Time to process a range of "
		<< args_deque.size() << " elements with std::deque :"
		<< time_deque << " us" << std::endl;
    return (0);
}