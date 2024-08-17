NAME = cub3D
CC = cc
W_FLAGS = -Wall -Wextra -Werror -O3 -g

PART = mandatory
SRC_DIR = $(PART)/src
INCLUDE_DIR = $(PART)/incl
OBJ_DIR = $(PART)/obj

LIBFT_DIR = $(PART)/libs/libft
MLX_DIR = $(PART)/libs/mlx_linux

MLX_FLAGS = -L./$(PART)/libs/mlx_linux -lmlx -I$(PART)/mlx_linux -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L./$(PART)/libs/libft -lft

MANDATORY_SRC = ft_free.c init_game.c main.c \
			controls/hooks.c controls/key_actions.c controls/key_actions_move.c controls/key_bindings.c \
			parser/checker_utils.c parser/cub_file.c parser/flood_fill_algo.c parser/free_variables_error.c \
			parser/hex_color.c parser/hex_colors_utils.c parser/init_vars.c parser/map.c parser/map_utils.c parser/parser.c \
			parser/player.c parser/store_map_utils.c parser/surfaces.c parser/surfaces_colors.c parser/textures.c \
			parser/textures_store_utils.c parser/textures_utils.c parser/wall.c parser/wall_utils.c \
			raycaster/load_images.c raycaster/raycaster.c raycaster/render.c raycaster/utils.c raycaster/utils_2.c

BONUS_SRC = ft_free.c game_loop.c init_game.c main.c \
			animation/animation.c animation/door.c animation/enemy.c animation/gun.c animation/ui.c \
			controls/key_actions/door_open_close.c controls/key_actions/key_actions.c controls/key_actions/menu.c \
			controls/key_actions/player_movement.c controls/key_actions/player_rotation.c controls/key_actions/player_shoot.c \
			controls/key_bindings.c \
			destroy_images/destroy_images.c destroy_images/enemy.c destroy_images/guns.c destroy_images/obstructions.c \
			destroy_images/ui.c \
			load_images/enemy.c load_images/guns.c load_images/load_images.c load_images/obstructions.c load_images/ui.c \
			parser/checker_utils.c parser/cub_file.c parser/flood_fill_algo.c parser/free_variables_error.c \
			parser/hex_color.c parser/hex_colors_utils.c parser/init_vars.c parser/map.c parser/map_utils.c parser/parser.c \
			parser/player.c parser/store_map_utils.c parser/surfaces.c parser/surfaces_colors.c parser/textures.c \
			parser/textures_store_utils.c parser/textures_utils.c parser/wall.c parser/wall_utils.c \
			raycaster/coll_points.c raycaster/ray_utils.c raycaster/raycaster.c raycaster/reset_data.c raycaster/save_data.c \
			raycaster/utils.c \
			render/ui/menu.c render/ui/minimap.c render/ui/player.c render/ui/utils.c render/enemy.c render/gun.c \
			render/obstructions.c render/render.c

ifeq ($(PART),bonus)
    SRC = $(BONUS_SRC)
else
    SRC = $(MANDATORY_SRC)
endif

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