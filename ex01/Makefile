# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwan <marwan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 21:40:14 by marwan            #+#    #+#              #
#    Updated: 2025/11/27 15:42:57 by marwan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp RPN.cpp

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