#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H

#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// screen
#define SCREEN_WIDTH 2560.0f
#define SCREEN_HEIGHT 1440.0f
#define DRAWING_SCALE (SCREEN_HEIGHT * 300.0f)
#define FIELD_OF_VIEW 60.0f

// vectors
#define SPEED 40

// directions
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// images
#define BACKGROUND "./textures/background.xpm"

// keys
#define ESC 53
#define W 119
#define S 115
#define A 97
#define D 100

typedef struct	s_image {
	void	*img;
	int     *data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int     created;
}	t_image;

typedef struct s_vectors
{
	float x;
	float y;
}   t_vectors;

typedef struct s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_image *image;
	float   square_width;
	float   square_height;
	char	**map;
	float	map_x;
	float	map_y;
	float	player_x;
	float	player_y;
	float	ray_new_x;
	float	ray_new_y;
	float	ray_angle;
	float   dists[(int)SCREEN_WIDTH];
	int     dist_idx;
	int     direction;
	void    *background;
	int     img_x;
	int     img_y;
	bool    keys[120];
	t_vectors *vectors;
	int     vec_idx;
}	t_game;

typedef struct s_ray_utils
{
	float	radians;
	float	shifted_x;
	float	shifted_y;
	float	new_x;
	float	new_y;
}	t_ray_utils;

typedef struct  s_raycaster
{
	float	dir_x;
	float	dir_y;
	float	len;
	float	x_iterator;
	float	y_iterator;
	float	speed;
	float   colis_x;
	float   colis_y;
}   t_raycaster;

void    calc_dir_vectors(t_game *game);
void	raycaster(t_game *game);
void	draw_map(t_game *game);
void	draw_crosshair(t_game *game);
void    draw_wall_line(t_game *game);
void	cast_ray(t_game *game, float ray_angle);
char	**init_test_map(void);
void    load_images_from_dir(t_game *game);
void	mark_player(t_game *game);

float	to_radians(float degrees);
void    calc_directions(t_raycaster *raycaster, t_game *game);
bool    is_ray_on_square_edge(t_raycaster *raycaster, t_game *game);
void    calc_collision_point_x_y(t_raycaster *raycaster, t_game *game);
bool    is_collision_point_a_wall(t_raycaster *raycaster, t_game *game);
void    set_ray_direction(t_raycaster *raycaster, t_game *game);
void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle);

// key_actions.c
void    change_angle_left(t_game *game);
void    change_angle_right(t_game *game);
int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);
int     keyrelease(const int keysymbol, t_game *game);
int	    loop_hook(t_game *game);
void    rotate_player_left(t_game *game);
void    rotate_player_right(t_game *game);
void	move_player_backward(t_game *game);
void    move_player_forward(t_game *game);

#endif //RAYCASTER_TEST_H
