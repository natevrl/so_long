# willcard = prend tout les fichiers *.c (variable propre au Makefile)
SRCS = so_long.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
# OBJS = variable SRC modifiee avec .o au lieu de .c comme extension
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

all : $(NAME)

# Pour MacOS
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#Pour Linux
%.o: %.c
	$(CC) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(OBJS) -g -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) mlx_linux/*.o libft/libft.a


clean : 
	rm -f $(OBJS)
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all
