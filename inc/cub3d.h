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

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx;


typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;








typedef struct s_data
{
    // Texture for each cardinal direction
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;

    int number_lines_map;

    

    int floor_color;
    bool floor_color_exist;
    int ceiling_color;
    bool ceiling_color_exist;

    char **map;

	bool map_error;

} t_data;

void    init_vars(t_data *data);



int		parser(void);
void	free_2d_array(char **array);
int		rgb_to_hex(int red, int green, int blue);
int		store_hex_color(char *line);

// bool checker_map(char *str);
// bool checker_map(char *str, char digit);

// CHECKER
char    *trim_rgb_input(char *str, char digit);
bool    color_input_exist(char *str, char digit);
int     size_array(char **array);
bool    rgb_correct_format(char *str, char digit);
bool    checker_surfaces_colors(char *str, char digit);

bool    store_surfaces_colors(char *line, t_data *data);
bool    store_texture_images(char *line, t_data *data);
bool store_map(t_data *data);

bool    check_input_exist(t_data *data);
bool    count_lines_map(t_data *data);

#endif