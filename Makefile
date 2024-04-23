CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

SRC_FILES = so_long.c read_map.c int_color.c map_validator.c init_blocks.c end_game.c path.c valid_path.c events.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ_FILES)
	$(CC) $(SRC_FILES) $(CFLAGS) -I. -I./libft -I./libmlx -L. -L./libft -L./libmlx -lmlx -lXext -lX11 -lm -lz -lft -o $(NAME)

libft/libft.a:
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make clean -C libft
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
