# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:23:56 by semin             #+#    #+#              #
#    Updated: 2021/11/30 18:13:25 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #나중에 추가
LIBS = -lpthread
NAME = philo
FILE = util\
		philo_action\
		philo_init\
		philo_time\
		philosophers\

SRC_DIR = ./src/
SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILE)))
OBJ_DIR = ./src/
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))
INC = -I./includes
SEG = -g -fsanitize=address

.c.o: $(SRC)
	$(CC) $(INC) -c -o $@ $<

all	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -g $(LIBS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
