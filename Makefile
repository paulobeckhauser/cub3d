.PHONY: all clean fclean re

NAME = cub3d
CC = gcc
W_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilbx -lmlx -L/usr/lib -Iminilbx -lXext -lX11 -lm -lz
SRC_DIR = src
INCLUDE_DIR = incl
OBJ_DIR = obj
SRC = main.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
MLX_DIR = minilbx

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(W_FLAGS) -I/usr/include -I$(INCLUDE_DIR) -I$(MLX_DIR) -O3 -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.c
	$(CC) $(W_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all