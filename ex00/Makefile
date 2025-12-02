# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwan <marwan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 02:59:28 by marwan            #+#    #+#              #
#    Updated: 2025/11/20 14:53:06 by marwan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRC = main.cpp bitcoin.cpp

CFLAGS =  -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

%o : %.cpp
	c++ $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean $(NAME)

.Phony : 
	re clean all fclean