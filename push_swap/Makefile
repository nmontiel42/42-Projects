NAME = push_swap
NAME_BONUS = checker

CFLAGS = -g -Wextra -Wall -Werror
LIBFT = ./libft
LIBPF = ./printf

SRCS	=	push.c\
			r_rotate.c\
			rotate.c\
			swap.c\
			check.c\
			check2.c\
			create_list.c\
			main.c\
			moves.c\
			sort_nums.c\
			utils.c\
			utils2.c\
			calculate_costs.c\
			target.c

SRCS_BONUS	= check.c\
			check2.c\
			create_list.c\
			utils.c\
			src_bonus/checker.c\
			src_bonus/checker2.c\
			src_bonus/actions.c\
			src_bonus/actions2.c\
			src_bonus/actions3.c\
			src_bonus/actions4.c\

CC = gcc

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: ${LIBFT}/libft.a ${LIBPF}/libftprintf.a $(NAME)

bonus: ${LIBFT}/libft.a ${LIBPF}/libftprintf.a $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(CC) -g $(CFLAGS) ${LIBFT}/libft.a ${LIBPF}/libftprintf.a $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) -g $(CFLAGS) ${LIBFT}/libft.a ${LIBPF}/libftprintf.a $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT)/libft.a:
	@${MAKE} -C ${LIBFT}

$(LIBPF)/libftprintf.a:
	@${MAKE} -C ${LIBPF}

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBPF} clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBPF} fclean

re: fclean all

.PHONY: all, clean, fclean, re, bonus