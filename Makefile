.PHONY: all clean fclean re

NAME = cub3d
CC = gcc
W_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L./libs/libft -lft
SRC_DIR = src
INCLUDE_DIR = incl
OBJ_DIR = obj
MLX_DIR = mlx_linux
SRC = main.c init_game.c controls/key_bindings.c controls/key_actions.c controls/hooks.c controls/utils.c \
 		raycaster/raycaster.c raycaster/init_test_map.c raycaster/draw_textures.c raycaster/load_images.c \
 		raycaster/utils.c raycaster/utils_2.c hex_color.c ft_free.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
LIBFT_DIR = libs/libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(OBJ) $(W_FLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(@D)
	@$(CC) $(W_FLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -s clean -C ./$(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s fclean -C ./$(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all