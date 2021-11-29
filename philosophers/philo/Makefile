# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:23:56 by semin             #+#    #+#              #
#    Updated: 2021/11/29 22:47:56 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #나중에 추가
LIBS = -lpthread
NAME = philo
SRC = $(addprefix src/, philosophers.c util.c philo_action.c philo_init.c philo_time.c)
INC = -I./includes
SEG = -g -fsanitize=address

all	: $(NAME)

$(NAME) :
	$(CC) $(LIBS) $(INC) $(SRC) -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
