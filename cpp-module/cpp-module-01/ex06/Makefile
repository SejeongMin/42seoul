CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = HarlFilter
SRCS = Harl.cpp \
		main.cpp

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