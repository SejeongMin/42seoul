# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 20:38:05 by semin             #+#    #+#              #
#    Updated: 2021/11/02 23:50:49 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=push_swap
SRC=$(addprefix src/, push_swap.c small_range.c sort.c stack.c util.c)
OBJ=$(SRC:.c=.o)
INC=-I./inc

all: $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY : all clean fclean re
