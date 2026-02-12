# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissat <maissat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 13:52:54 by marwan            #+#    #+#              #
#    Updated: 2026/02/12 18:32:56 by maissat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PMergeMe

SRC = main.cpp PmergeMe.cpp

CFLAGS =  -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	c++ $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)
	mkdir -p obj
	mv *.o obj/

clean : 
	rm -f obj/*.o
fclean : clean
	rm -f $(NAME)
re : fclean $(NAME)

.Phony : 
	re clean all fclean