#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H

#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

// screen
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DRAWING_SCALE (SCREEN_HEIGHT * 200)
#define FIELD_OF_VIEW 60.0f

// images
#define TEXTURE_SIZE 500
#define NORTH_TEXTURE "./mandatory/textures/walls/wall_default_texture.xpm"
#define SOUTH_TEXTURE "./mandatory/textures/walls/wall_default_texture.xpm"
#define WEST_TEXTURE "./mandatory/textures/walls/wall_default_texture.xpm"
#define EAST_TEXTURE "./mandatory/textures/walls/wall_default_texture.xpm"

// vectors
#define SPEED 40.0f

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

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	float		square_size;
	char		**map;
	float		player_x;
	float		player_y;
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
	t_vectors	*vectors;
	int			vec_idx;
	void		*north_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
}	t_game;

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

void    calc_dir_vectors(t_game *game);
void	raycaster(t_game *game);
void	render_game(t_game *game);
void    render_wall_line(t_game *game);
void	cast_ray(t_game *game, float ray_angle);
char	**init_test_map(void);
void    load_images_from_dir(t_game *game);
void	mark_player(t_game *game);

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

#endif //RAYCASTER_TEST_H
