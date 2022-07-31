CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = animal
SRCS = Animal.cpp \
		Cat.cpp	\
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
