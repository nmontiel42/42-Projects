NAME = iter
CC = clang++

SRC = main.cpp

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address,undefined

OBJ_SRC = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CPPFLAGS) $(OBJ_SRC) -o $(NAME)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_SRC)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
