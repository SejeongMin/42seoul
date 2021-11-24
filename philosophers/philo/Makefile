# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:23:56 by semin             #+#    #+#              #
#    Updated: 2021/11/24 18:45:55 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #나중에 추가
NAME = philo
SRC = $(addprefix src/, philosophers.c util.c)
INC = -I./includes

all	: $(NAME)

$(NAME) :
	$(CC) $(INC) -g -fsanitize=address $(SRC) -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
