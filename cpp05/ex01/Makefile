NAME=Bureaucrat

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

CXX = c++

SRCS= main.cpp Bureaucrat.cpp Form.cpp

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