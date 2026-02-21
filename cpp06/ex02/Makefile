NAME=identify

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

CXX = c++

SRCS= Base.cpp A.cpp B.cpp C.cpp Functions.cpp main.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re