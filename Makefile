SRCS =	game/kill.c\
		game/map_put_tiles.c\
		game/moove_detection.c\
		game/init_game.c\
		game/main.c\
		game/maps.c\
		game/player_moove.c\
		game/error.c\
		game/utils.c\
		game/map_error.c\
		libs/get_next_line/get_next_line.c\
		libs/get_next_line/get_next_line_utils.c\


OBJS		= $(SRCS:.c=.o)
LIBFT		= libs/libft/libft.a
MINILIBX	= minilibx-linux/obj/*.o


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= so_long

all : $(NAME)

# Pour MacOS
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#Pour Linux
%.o: %.c
	$(CC) ${CFLAGS} -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libs/libft/
	make -C minilibx-linux
	$(CC)  $(OBJS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) ${MINILIBX} ${LIBFT}


clean : 
	rm -f $(OBJS)
	make fclean -C libs/libft/
	make clean -C minilibx-linux

fclean : clean
	rm -f $(NAME)

re : fclean all
