#ifndef CUB3D_H
#define CUB3D_H

#include "../libs/libft/inc/ft_printf.h"
#include "../libs/libft/inc/get_next_line.h"
#include "../libs/libft/inc/libft.h"
#include <fcntl.h> // open file function
#include <errno.h>
#include <string.h>
#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "color.h"

// screen
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DRAWING_SCALE (SCREEN_HEIGHT * 200)
#define FIELD_OF_VIEW 60.0f
#define SQUARE_SIZE 100

// images
#define TEXTURE_SIZE 500

// vectors
#define SPEED 10

// wall_directions
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// keys
#define ESC 0
#define W 1
#define S 2
#define A 3
#define D 4
#define LEFT_ARROW 5
#define RIGHT_ARROW 6

typedef struct	s_image {
	void		*img;
	int			*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_vectors
{
	float		x;
	float		y;
}   t_vectors;

typedef struct  s_raycaster
{
	float		dir_x;
	float		dir_y;
	float		len;
	float		x_iterator;
	float		y_iterator;
	float		speed;
	float		colis_x;
	float		colis_y;
}   t_raycaster;

typedef struct s_player
{
	char		direction;
	float		x;
	float		y;
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

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	float		square_size;
	float		ray_new_x;
	float		ray_new_y;
	float		ray_main_angle;
	float		ray_hit_x;
	float		ray_hit_y;
	float		wall_dists[SCREEN_WIDTH];
	int			dist_idx;
	int			wall_direction;
	int			img_x;
	int			img_y;
	bool		keys[7];
	void		*north_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
	t_vectors	*vectors;
	int			vec_idx;
	t_data		*data;
}	t_game;

void    calc_dir_vectors(t_game *game);
void	raycaster(t_game *game);
void	render_game(t_game *game);
void    render_wall_line(t_game *game);
void	cast_ray(t_game *game, float ray_angle);
char	**init_test_map(void);
void    load_images_from_dir(t_game *game);
// void load_images_from_dir(t_game *game, t_data *data);

float	to_radians(float degrees);
void    calc_directions(t_raycaster *raycaster, t_game *game);
bool    is_ray_on_square_edge(t_raycaster *raycaster, t_game *game);
void    calc_collision_point_x_y(t_raycaster *raycaster, t_game *game);
bool    is_collision_point_wall(t_raycaster *raycaster, t_game *game);
bool    is_collision_point_closed_door(t_raycaster *raycaster, t_game *game);
void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle, float *dist);
int		get_pixel_color(void *img_ptr, int x, int y);

// key_actions.c
int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);
int     keyrelease(int keysymbol, t_game *game);
int     mouse_move(int x, int y, t_game *game);
int	    loop_hook(t_game *game);
void    rotate_player_left(t_game *game);
void    rotate_player_right(t_game *game);
void	move_player_backward(t_game *game);
void    move_player_forward(t_game *game);
void    move_player_left(t_game *game);
void    move_player_right(t_game *game);

void    set_ray_direction(t_raycaster *raycaster, t_game *game, int *direction);
void	render_background(t_game *game);

bool			check_extension(t_data *data, char *str, char *extension);
bool			check_if_map_element(char *str);
bool			check_player(t_data *data);
bool			check_xpm_extension(t_data *data, char *str);
char			*clean_str_color(t_data *data, int i, char surf);
bool			clean_store_hex_color(t_data *data, int i, char surf);
bool			count_lines_map(t_data *data, char *str);
bool			floor_ceiling_lines(char **array, t_data *data, int i);
void			free_2d_array(char **array);
int				free_variables_error(t_data *data);
void			init_vars(t_data *data);
// int				parser(char *str);
int				parser(char *str, t_data *data);
void			replace_error_message(t_data *data, char *str);
int				rgb_to_hex(int red, int green, int blue);
int				size_array(char **array);
bool			store_cub_file(t_data *data, char *str);
bool			store_hex_color(char *str, t_data *data, char surf);
bool			store_textures(t_data *data);
bool			store_surface_colors(t_data *data);
bool			store_map(t_data *data);
void	render_background(t_game *game);
// void    		init_game(t_game *game);
void    init_game(t_game *game, t_data *data);
void    		init_keys(t_game *game);

#endif
