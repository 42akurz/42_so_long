CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar cr
NAME_LIB= libft.a
NAME = libmlx.a
SOURCES = ./main.c ./get_next_line/get_next_line.c ./create_images.c ./map_content.c ./key_hooks.c ./movement.c ./exit.c ./check_maptype.c
OBJECTS = $(SOURCES:.c=.o)

#build everything
all: $(NAME)

#make libft
LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME_LIB)
	make -C ./mlx
	cp ./mlx/libmlx.a $(NAME)

#creates a static library
$(NAME): LIB $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libft.a libmlx.a -framework OpenGL -framework AppKit -o so_long

#removes all *.o files
clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft
	make clean -C ./mlx

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) ./mlx/libmlx.a
	$(RM) libmlx.a
	$(RM) libft.a
	$(RM) so_long

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all