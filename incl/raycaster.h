#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H

#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// keys
#define ESC 65307
#define W 119
#define S 115
#define A 97
#define D 100

// textures
#define FLOOR "./textures/floor.xpm"
#define PLAYER "./textures/player.xpm"
#define WALL "./textures/wall.xpm"

// typedef struct s_line
// {
// 	int             idx;
// 	char            *sprites;
// 	int             len;
// 	struct s_line    *prev;
// 	struct s_line    *next;
// }   t_line;

typedef struct s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	int		img_x;
	int		img_y;
	void    *txt_floor;
	void    *txt_player;
	void    *txt_wall;
	char	**map;
	double	map_x;
	double	map_y;
	double	player_x;
	double	player_y;
	int		player_marked;
	double	ray_x;
	double	ray_y;
	double	ray_new_x;
	double	ray_new_y;
	double	ray_angle;
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
void	draw_collision(const t_game *game, double x_iterator, double y_iterator);
void	draw_map(t_game *game);
void	draw_player(const t_game *game);
void	draw_ray(t_game *game);
char	**init_test_map(void);
void	load_images(t_game *textures);
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
