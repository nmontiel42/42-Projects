NAME	= so_long
LIBMLX	= ./MLX42
LIBFT	= ./libft
LIBPF	= ./printf
LIBGN	= ./get_next_line

HEADERS	= -I ./includes -I ${LIBMLX}/include -I ${LIBFT} -I ${LIBGN} -I ${LIBPF}
LIBGL	= -lglfw -L"/Users/nmontiel/.brew/opt/glfw/lib"
LIBS	= ${LIBGL} ${LIBMLX}/libmlx42.a ${LIBFT}/libft.a ${LIBPF}/libftprintf.a ${LIBGN}/get_next_line.a
SRCS	= Src/main.c \
			Src/check_map.c \
			Src/check_map2.c \
			Src/check_map3.c \
			Src/collectable.c \
			Src/visualizer.c \
			Src/map.c \
			Src/movements.c

OBJS	= ${SRCS:.c=.o}

all: libft libmlx libpf libgn ${NAME}

libft:
	@${MAKE} -C ${LIBFT}

libmlx:
	@${MAKE} -C ${LIBMLX}

libpf:
	@${MAKE} -C ${LIBPF}

libgn:
	@${MAKE} -C ${LIBGN}

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	@${CC} ${DFLAGS} ${OBJS} ${LIBS} ${HEADERS} -o ${NAME}

clean:
	@rm -f ${OBJS}
	@${MAKE} -C ${LIBFT} clean
	@${MAKE} -C ${LIBMLX} clean
	@${MAKE} -C ${LIBPF} clean
	@${MAKE} -C ${LIBGN} clean

fclean: clean
	@rm -f ${NAME}
	@${MAKE} -C ${LIBFT} fclean
	@${MAKE} -C ${LIBMLX} fclean
	@${MAKE} -C ${LIBPF} fclean
	@${MAKE} -C ${LIBGN} fclean
	
re: clean all

norma: 
	norminette ${SRCS}

.PHONY: all, clean, fclean, re, libmlx, libft