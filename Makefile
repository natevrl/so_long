# willcard = prend tout les fichiers *.c (variable propre au Makefile)
SRCS = so_long.c
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
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) mlx_linux/*.o


clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
