NAME = Bureaucrat3
CC = clang++

SRC = Bureaucrat.cpp \
		main.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

CPPFLAGS = -std=c++98 -Wall -Werror -Wextra -fsanitize=address

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
