# willcard = prend tout les fichiers *.c (variable propre au Makefile)
SRCS = so_long.c
# OBJS = variable SRC modifiee avec .o au lieu de .c comme extension
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long

all : $(NAME)

# %.o : %.c = Toutes les cibles *.o seront creees avec les dependances *.c
# raccourci = .c.o comme nom de regle
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
