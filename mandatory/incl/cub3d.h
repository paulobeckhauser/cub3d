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
# include <errno.h>

# include "color.h"
# include "raycaster.h"

typedef struct s_player
{
	char		direction;
	int			x;
	int			y;
}				t_player;

typedef struct s_data
{
	int			color_ceiling;
	int			color_ceiling_count;
	int			color_floor;
	int			color_floor_count;
	char		**cub_file;
	int			line_start_map_position;
	int			line_end_map_position;
	char		**map_element;
	char		*map_error_message;
	int			number_lines_map;
	int			number_lines_map_element;
	t_player	*player;
	int			text_count_n;
	int			text_count_s;
	int			text_count_w;
	int			text_count_e;
	char		*texture_north;
	char		*texture_south;
	char		*texture_west;
	char		*texture_east;
}				t_data;

void	free_2d_array(char **array);
int		rgb_to_hex(int red, int green, int blue);
int		store_hex_color(char *line);

void    init_game(t_game *game);
void    init_keys(t_game *game);


#endif