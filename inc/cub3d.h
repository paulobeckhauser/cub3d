#ifndef CUB3D_H
#define CUB3D_H

# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"

# include "color.h"


# include "../libs/mlx_linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> // open file function
# include <stdbool.h>

# include <errno.h>
# include <string.h>

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




typedef struct s_coord
{
    float x;
    float y;
}   t_coord;


typedef struct s_map
{
    t_coord         coord;
    struct s_map   *next;

}   t_map;





typedef struct s_data
{
    // Texture for each cardinal direction
    char **cub_file;
    
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;

    int number_lines_map;


    int floor_color;
    bool floor_color_exist;
    int ceiling_color;
    bool ceiling_color_exist;

    
    char **map_element;

    int number_lines_map_element;


	bool map_error;
    char *map_error_message;
    int element_position;
    int line_start_map_position;

    bool map_correct_position;

} t_data;

void    init_vars(t_data *data);



int parser(char *str);
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
// bool    checker_surfaces_colors(char *str, char digit);
bool checker_surfaces_colors(t_data *data, char *str, char digit);

bool    store_surfaces_colors(char *line, t_data *data);
bool    store_texture_images(char *line, t_data *data);
bool store_cub_file(t_data *data, char *str);

// bool    check_input_exist(t_data *data);
bool check_input_floor_texture_exist(t_data *data);
bool    count_lines_map(t_data *data);

// int     free_variables_error(t_data *data);
int free_variables_error(t_data *data);

bool check_map_content_last_element(t_data *data);

bool size_map_element(t_data *data);
bool    check_empty_line(char *str);
bool check_map_element(char *str);

bool store_map_element(t_data *data);


bool check_walls_in_edges(t_data *data);
void replace_error_message(t_data *data, char *str);
bool check_extension(t_data *data, char *str);
void get_map_elem_info(t_data *data);
bool new_checker_borders(t_data * data);

void print_returned_map(t_data *data);


#endif