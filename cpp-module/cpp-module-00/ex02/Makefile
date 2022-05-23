# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 22:38:11 by semin             #+#    #+#              #
#    Updated: 2022/05/23 22:38:13 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = account
SRCS = test.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $@

.cpp.o :
	$(CC) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
