# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 21:17:47 by semin             #+#    #+#              #
#    Updated: 2021/09/21 20:51:55 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=so_long
SRC=main.c util.c key_event.c map_parser.c free.c
OBJ=$(SRC:.c=.o)
INC=-I/usr/local/include/
LIB=-L/usr/local/lib/
EXT=../get_next_line/*.o ../libft/libft.a ../ft_printf/libftprintf.a
CFLAGS=-lmlx -framework OpenGL -framework AppKit

all:
	$(CC) $(INC) $(LIB) $(CFLAGS) $(SRC) $(EXT) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
