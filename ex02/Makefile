NAME =  account

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

SRC =	Account.cpp\
		tests.cpp

OBJ = ${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@$(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re