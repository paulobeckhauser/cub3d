#ifndef RAYCASTER_TEST_H
#define RAYCASTER_TEST_H

#include "../libs/mlx_linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

// screen
#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define DRAWING_SCALE (SCREEN_HEIGHT * 200)
#define FIELD_OF_VIEW 60.0f
#define MINIMAP_SCALE 20

// images
#define TEXTURE_SIZE 500
#define NORTH_TEXTURE "./textures/walls/wall_default_texture.xpm"
#define SOUTH_TEXTURE "./textures/walls/wall_default_texture.xpm"
#define WEST_TEXTURE "./textures/walls/wall_default_texture.xpm"
#define EAST_TEXTURE "./textures/walls/wall_default_texture.xpm"
#define FLOOR_TEXTURE "./textures/minimap/floor_texture.xpm"
#define WALL_TEXTURE "./textures/minimap/wall_texture.xpm"
#define PLAYER_TEXTURE "./textures/minimap/player_ln_texture.xpm"
#define	GUN_TEXTURE "./textures/guns/desert_eagle_texture.xpm"
#define DOOR_FRAME_4_4 "./textures/door/door_frame_4_4.xpm"
#define DOOR_FRAME_3_4 "./textures/door/door_frame_3_4.xpm"
#define DOOR_FRAME_2_4 "./textures/door/door_frame_2_4.xpm"
#define DOOR_FRAME_1_4 "./textures/door/door_frame_1_4.xpm"
#define DOOR_FRAME_0_4 "./textures/door/door_frame_0_4.xpm"
#define DARK_PRIEST_0_9 "./texture/enemies/dark_priest_0_9"
#define DARK_PRIEST_1_9 "./texture/enemies/dark_priest_1_9"
#define DARK_PRIEST_2_9 "./texture/enemies/dark_priest_2_9"
#define DARK_PRIEST_3_9 "./texture/enemies/dark_priest_3_9"
#define DARK_PRIEST_4_9 "./texture/enemies/dark_priest_4_9"
#define DARK_PRIEST_5_9 "./texture/enemies/dark_priest_5_9"
#define DARK_PRIEST_6_9 "./texture/enemies/dark_priest_6_9"
#define DARK_PRIEST_7_9 "./texture/enemies/dark_priest_7_9"
#define DARK_PRIEST_8_9 "./texture/enemies/dark_priest_8_9"
#define DARK_PRIEST_9_9 "./texture/enemies/dark_priest_9_9"


// vectors
#define SPEED 40.0f
#define DOOR_OPEN_DISTANCE 170

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
#define E 7

// animation
#define DOOR_FRAMES 5
#define DOOR_FRAME_DURATION 1200000

typedef struct	s_image {
	void	*img;
	int     *data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
	float   square_size;
	char	**map;
	float	player_x;
	float	player_y;
	float	ray_new_x;
	float	ray_new_y;
	float	ray_main_angle;
	float   ray_hit_x;
	float   ray_hit_y;
	float	ray_open_door_hit_x;
	float	ray_open_door_hit_y;
	float   wall_dists[SCREEN_WIDTH];
	float	door_dists[SCREEN_WIDTH];
	float   enemy_dists[SCREEN_WIDTH];
	int     dist_idx;
	int     wall_direction;
	int     door_direction;
	int     enemy_direction;
	int     img_x;
	int     img_y;
	bool    keys[8];
	t_vectors *vectors;
	int     vec_idx;
	void    *north_texture;
	void    *south_texture;
	void    *west_texture;
	void    *east_texture;
	void    *floor_texture;
	void    *wall_texture;
	void	*player_texture;
	void	*gun_texture;
	void	*door_texture[5];
	void    *door_current_texture;
	void    *dark_priest_texture[10];
	void    *current_dark_priest_texture;
	long    door_animation_start_time;
	bool    hit_closed_door;
	bool	hit_opened_door;
	bool    door_visible;
	bool    door_are_opening;
	bool    door_are_closing;
	float   closest_door_distance;
	float   prev_door_distance;
	float   enemy_hit_x;
	float   enemy_hit_y;
	bool    enemy_visible;
	int     mouse_x;
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
void	render_map(t_game *game);
void    render_minimap(t_game *game);
void    render_minimap_player(t_game *game);
void	render_gun(t_game *game);
void	render_crosshair(t_game *game);
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
void    set_wall_ray_direction(t_raycaster *raycaster, t_game *game);
void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle);
int		get_pixel_color(void *img_ptr, int x, int y);
// key_actions.c
int	    close_game(t_game *game);
void	init_hooks(t_game *game);
int    	keypress(int keysymbol, t_game *game);
int     keyrelease(const int keysymbol, t_game *game);
int     mouse_move(int x, int y, t_game *game);
int	    loop_hook(t_game *game);
void    rotate_player_left(t_game *game);
void    rotate_player_right(t_game *game);
void	move_player_backward(t_game *game);
void    move_player_forward(t_game *game);
void    move_player_left(t_game *game);
void    move_player_right(t_game *game);

bool    is_collision_point_opened_door(t_raycaster *raycaster, t_game *game);
void    calc_ray_distance_door(t_raycaster *raycaster, t_game *game, float ray_angle);
void    render_closer_wall_line(t_game *game);
void    set_door_ray_direction(t_raycaster *raycaster, t_game *game);
void    open_close_door(t_game *game);
void    save_closest_door_distance(t_game *game, float dist);
bool    is_collision_point_enemy(t_raycaster *raycaster, t_game *game);
void    set_ray_direction(t_raycaster *raycaster, t_game *game, int *direction);

#endif //RAYCASTER_TEST_H
