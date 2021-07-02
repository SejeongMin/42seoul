# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semin <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 11:09:08 by semin             #+#    #+#              #
#    Updated: 2021/05/17 16:31:42 by semin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

P1_SRC = ft_memcpy.c ft_memccpy.c ft_memset.c ft_bzero.c ft_memchr.c\
		 ft_memcmp.c ft_memmove.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
		 ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		 ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
P2_SRC = ft_strjoin.c ft_split.c ft_substr.c ft_strtrim.c ft_strmapi.c\
		 ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		 ft_putnbr_fd.c
B_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

INC = ./libft.h

SRCS = $(P1_SRC) $(P2_SRC)

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

ifdef BONUS_TEST
	OBJ = $(B_OBJS)
else
	OBJ = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJS) $(B_OBJS)
	ar crs $@ $^

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : 
	$(MAKE) BONUS_TEST=1 $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re bonus
