# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 21:17:47 by semin             #+#    #+#              #
#    Updated: 2021/09/13 19:24:49 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=so_long
SRC=main.c util.c key_event.c
OBJ=$(SRC:.c=.o)
INC=/usr/local/include/
LIB=/usr/local/lib/
CFLAGS=-lmlx -framework OpenGL -framework AppKit

all:
	gcc -g -fsanitize=address -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o so_long ../get_next_line/*.o $(SRC) ../libft/libft.a

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
