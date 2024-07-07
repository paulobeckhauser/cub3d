#ifndef CUB3D_H
#define CUB3D_H

# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"

# include "../libs/mlx_linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> // open file function
# include <stdbool.h>

# include "raycaster.h"



typedef struct s_data
{
	// Texture for each cardinal wall_direction
	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;

	// RGB color for flor and ceiling
	// char *floor_color_hex;
	// char *ceiling_color;
	int floor_color;
	int ceiling_color;
	bool map_error;
} t_data;

void	free_2d_array(char **array);
int		rgb_to_hex(int red, int green, int blue);
int		store_hex_color(char *line);

void    init_game(t_game *game);
void    init_keys(t_game *game);

int checker_map(char *str);

bool floor_line_exist(char *str, char digit);

#endif