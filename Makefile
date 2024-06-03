.PHONY: all clean fclean re

NAME = cub3d
CC = cc
W_FLAGS = -Wall -Wextra -Werror #-fsanitize=address
MLX_FLAGS = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L./libs/libft -lft
SRC_DIR = src
INCLUDE_DIR = incl
OBJ_DIR = obj
MLX_DIR = mlx_linux
LIBFT_DIR = libs/libft


# CHECKER_DIR := $(SRC_DIR)/checker/

# CHECKER_SRC := $(CHECKER_DIR)check_surface.c \

SRC := 			main.c \
				parser.c \
				ft_free.c \
				hex_color.c \
				init_vars.c \
				check_surface.c \
				checker_utils.c \
				store_input.c \
				cub_file.c \
				free_variables_error.c \
				checker_map.c \





OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all: $(NAME)

$(NAME):	$(OBJ)
					@make -s -C $(LIBFT_DIR)
					@$(CC) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
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