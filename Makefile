CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

SRC_FILES = so_long.c read_map.c int_color.c map_validator.c init_blocks.c end_game.c path.c valid_path.c

all: $(NAME)

$(NAME): libft/libft.a
	$(CC) $(SRC_FILES) -I. -I./libft -L. -L./libft -lmlx -lXext -lX11 -lm -lz -lft -o $(NAME)

libft/libft.a:
	make -C libft

clean: 
	make clean -C libft
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

src:
	$(CC) $(CFLAGS) $(SRC_FILES) -g -I. -I./libft -L. -L./libft -lmlx -lXext -lX11 -lm -lz -lft -o $(NAME)

