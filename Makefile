.PHONY: all clean fclean re

NAME = cub3d
CC = gcc
W_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
SRC_DIR = src
INCLUDE_DIR = incl
OBJ_DIR = obj
MLX_DIR = mlx_linux
SRC = main.c controls/key_bindings.c controls/key_actions.c controls/hooks.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CC) $(W_FLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all