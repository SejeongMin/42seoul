# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 04:20:53 by semin             #+#    #+#              #
#    Updated: 2022/04/09 02:48:24 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRCS = main.cpp contact.cpp phonebook.cpp
OBJS = $(SRCS:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
