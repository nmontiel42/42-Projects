NAME = phonebook
CPP = g++
FLAGS = -I/usr/include/c++/98 -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
		PhoneBook.cpp \
		Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) -o $@ $(OBJ)
	@echo "$(NAME) compilation successful."

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Compiled objects have been removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) Cleaned."

re: fclean all

.PHONY: all clean fclean re