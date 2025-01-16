# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 11:33:58 by nmontiel          #+#    #+#              #
#    Updated: 2025/01/16 17:11:58 by nmontiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

LIB = ar rcs

SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = ${SRC:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re