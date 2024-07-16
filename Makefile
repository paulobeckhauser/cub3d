NAME = cub3d
CC = cc
W_FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# Default to mandatory part
PART = mandatory
SRC_DIR = $(PART)/src
INCLUDE_DIR = $(PART)/incl
OBJ_DIR = $(PART)/obj

# Adjusted LIBFT_DIR and MLX_DIR to dynamically reference libs based on PART
LIBFT_DIR = $(PART)/libs/libft
MLX_DIR = $(PART)/libs/mlx_linux

# Adjusted to dynamically reference libs based on PART
MLX_FLAGS = -L./$(PART)/libs/mlx_linux -lmlx -I$(PART)/mlx_linux -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L./$(PART)/libs/libft -lft

SRC = main.c init_game.c controls/key_bindings.c controls/key_actions.c controls/key_actions_move.c controls/hooks.c \
        raycaster/raycaster.c raycaster/render.c raycaster/load_images.c \
        raycaster/utils.c raycaster/utils_2.c ft_free.c parser/parser.c parser/checker_utils.c \
		parser/cub_file.c parser/free_variables_error.c parser/hex_color.c parser/hex_colors_utils.c parser/init_vars.c parser/map.c \
		parser/map_utils.c parser/surfaces_colors.c parser/surfaces.c parser/textures_store_utils.c parser/textures_utils.c \
		parser/textures.c parser/player.c parser/store_map_utils.c parser/flood_fill_algo.c parser/wall.c parser/wall_utils.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus:
	$(MAKE) PART=bonus all

$(NAME): $(OBJ)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(OBJ) $(W_FLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(W_FLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -s clean -C $(LIBFT_DIR)
	@rm -rf mandatory/obj bonus/obj

fclean: clean
	@make -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
