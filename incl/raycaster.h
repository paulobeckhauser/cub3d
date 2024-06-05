#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H

#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// screen
#define SCREEN_WIDTH 2560.0
#define SCREEN_HEIGHT 1440.0
#define DRAWING_SCALE (SCREEN_HEIGHT * 300.0)

// directions
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// images
#define BACKGROUND "./textures/background.xpm"

// keys
#define ESC 65307
#define W 119
#define S 115
#define A 97
#define D 100

typedef struct s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	double  square_width;
	double  square_height;
	char	**map;
	double	map_x;
	double	map_y;
	double	player_x;
	double	player_y;
	double	ray_main_x;
	double	ray_main_y;
	double	ray_new_x;
	double	ray_new_y;
	double	ray_angle;
	double  dists[(int)SCREEN_WIDTH];
	int     dist_idx;
	int     direction;
	void    *background;
	int     img_x;
	int     img_y;
}	t_game;

typedef struct s_ray_utils
{
	double	radians;
	double	shifted_x;
	double	shifted_y;
	double	new_x;
	double	new_y;
}	t_ray_utils;

void	cast_rays(t_game *game);
void	calc_new_ray_x_y(t_game *game);
void	draw_map(t_game *game);
void    draw_wall_line(t_game *game);
void	draw_ray(t_game *game);
char	**init_test_map(void);
void    load_images(t_game *game);
void	mark_player(t_game *game);
void	mark_main_ray(t_game *game);
void	move_player_backward(t_game *game);
void    move_player_forward(t_game *game);
double	to_radians(double degrees);

// key_actions.c
void    change_angle_left(t_game *game);
void    change_angle_right(t_game *game);
int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);
void    rotate_player_left(t_game *game);
void    rotate_player_right(t_game *game);

#endif //RAYCASTER_TEST_H
