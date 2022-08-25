NAME = so_long

FILES = $(wildcard ./source/ft_*.c ./ft_printf/ft_*.c ./gnl_fake/*.c)
MINILIBX = ./mlx/libmlx.a
OBJ = $(FILES:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra
LFLAGS = -framework OpenGL -framework Appkit

all : $(MINILIBX) $(FILES) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) $(MINILIBX) -o $(NAME) -Imlx

$(MINILIBX):
	make -C mlx

clean:
	@rm -rf $(OBJ)
	@echo "\033[92mobject files were deleted\033[0m"

fclean:
	@rm -rf $(NAME)
	make -C mlx clean
	@rm -rf $(OBJ)
	@echo "\033[92mall files were deleted\033[0m"

re: fclean all



.PHONY: clean fclean re run all
