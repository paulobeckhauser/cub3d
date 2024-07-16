#ifndef CUB3D_H
#define CUB3D_H

#include "../libs/libft/inc/ft_printf.h"
#include "../libs/libft/inc/get_next_line.h"
#include "../libs/libft/inc/libft.h"
#include "../libs/mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // open file function
#include <stdbool.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include "color.h"

// screen
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define DRAWING_SCALE (SCREEN_HEIGHT * 200)
#define FIELD_OF_VIEW 60.0f
#define MINIMAP_SCALE 20
# define SQUARE_SIZE 100

// images
#define TEXTURE_SIZE 500
#define MINIMAP_BG "./bonus/textures/minimap/minimap_bg.xpm"
#define FLOOR_TEXTURE "./bonus/textures/minimap/floor_texture.xpm"
#define WALL_TEXTURE "./bonus/textures/minimap/wall_texture.xpm"
#define PLAYER_TEXTURE "./bonus/textures/minimap/player_ln_texture.xpm"
#define SKULL "./bonus/textures/minimap/skull.xpm"
#define	GUN_0_4 "./bonus/textures/guns/desert_eagle_0_4.xpm"
#define GUN_1_4 "./bonus/textures/guns/desert_eagle_1_4.xpm"
#define GUN_2_4 "./bonus/textures/guns/desert_eagle_2_4.xpm"
#define GUN_3_4 "./bonus/textures/guns/desert_eagle_3_4.xpm"
#define GUN_4_4 "./bonus/textures/guns/desert_eagle_4_4.xpm"
#define DOOR_FRAME_4_4 "./bonus/textures/door/door_frame_4_4.xpm"
#define DOOR_FRAME_3_4 "./bonus/textures/door/door_frame_3_4.xpm"
#define DOOR_FRAME_2_4 "./bonus/textures/door/door_frame_2_4.xpm"
#define DOOR_FRAME_1_4 "./bonus/textures/door/door_frame_1_4.xpm"
#define DOOR_FRAME_0_4 "./bonus/textures/door/door_frame_0_4.xpm"
#define DARK_PRIEST_0_9 "./bonus/textures/enemies/dark_priest_0_9.xpm"
#define DARK_PRIEST_1_9 "./bonus/textures/enemies/dark_priest_1_9.xpm"
#define DARK_PRIEST_2_9 "./bonus/textures/enemies/dark_priest_2_9.xpm"
#define DARK_PRIEST_3_9 "./bonus/textures/enemies/dark_priest_3_9.xpm"
#define DARK_PRIEST_4_9 "./bonus/textures/enemies/dark_priest_4_9.xpm"
#define DARK_PRIEST_5_9 "./bonus/textures/enemies/dark_priest_5_9.xpm"
#define DARK_PRIEST_6_9 "./bonus/textures/enemies/dark_priest_6_9.xpm"
#define DARK_PRIEST_7_9 "./bonus/textures/enemies/dark_priest_7_9.xpm"
#define DARK_PRIEST_8_9 "./bonus/textures/enemies/dark_priest_8_9.xpm"
#define DARK_PRIEST_9_9 "./bonus/textures/enemies/dark_priest_9_9.xpm"
#define HP_0 "./bonus/textures/hp/0.xpm"
#define HP_10 "./bonus/textures/hp/10.xpm"
#define HP_20 "./bonus/textures/hp/20.xpm"
#define HP_30 "./bonus/textures/hp/30.xpm"
#define HP_40 "./bonus/textures/hp/40.xpm"
#define HP_50 "./bonus/textures/hp/50.xpm"
#define HP_60 "./bonus/textures/hp/60.xpm"
#define HP_70 "./bonus/textures/hp/70.xpm"
#define HP_80 "./bonus/textures/hp/80.xpm"
#define HP_90 "./bonus/textures/hp/90.xpm"
#define HP_100 "./bonus/textures/hp/100.xpm"
#define GAME_OVER "./bonus/textures/menu/game_over.xpm"

// vectors
#define SPEED 20.0f
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
#define MOUSE_LEFT_CLICK 8

// animation
#define DOOR_FRAMES 5
#define DOOR_FRAME_DURATION 1200000
#define ENEMY_FRAMES 10
#define ENEMY_FRAME_DURATION 4800000
#define GUN_FRAMES 5
#define GUN_FRAME_DURATION 600000

typedef struct	s_image
{
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

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_textures
{
	void    *north_texture;
	void    *south_texture;
	void    *west_texture;
	void    *east_texture;
	void    *minimap_bg;
	void    *floor_texture;
	void    *wall_texture;
	void    *skull;
	void	*player_texture;
	void	*gun_texture[5];
	void    *gun_current_texture;
	void	*door_texture[5];
	void    *door_current_texture;
	void    *dark_priest_texture[10];
	void    *dark_priest_current_texture;
	void    *hp_texture[11];
	void    *hp_current_texture;
	void	*game_over_texture;
}	t_textures;

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
	float	ray_door_hit_x;
	float	ray_door_hit_y;
	float   wall_dists[SCREEN_WIDTH];
	float	door_dists[SCREEN_WIDTH];
	float   enemy_dists[SCREEN_WIDTH];
	bool    body_hit[SCREEN_WIDTH];
	int     dist_idx;
	int     wall_direction;
	int     door_direction;
	int		enemy_x;
	int		enemy_y;
	int     img_x;
	int     img_y;
	bool    keys[9];
	t_vectors *vectors;
	int     vec_idx;
	long    door_animation_start_time;
	bool    hit_closed_door;
	bool	hit_opened_door;
	bool    closed_door_visible;
	bool    open_door_visible;
	bool    door_are_opening;
	bool    door_are_closing;
	float   closest_door_distance;
	float   prev_door_distance;
	long    enemy_animation_start_time;
	long    gun_animation_start_time;
	float   closest_enemy_distance;
	float   prev_enemy_distance;
	float   ray_enemy_hit_x;
	float   ray_enemy_hit_y;
	bool    hit_enemy;
	bool    enemy_visible;
	int     mouse_x;
	int     first_enemy_dist;
	bool	hp_frame_updated;
	bool	player_dead;
	t_textures	*textures;
	t_data  *data;
}	t_game;

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
void	render_game(t_game *game);
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
void    calc_ray_distance(t_raycaster *raycaster, t_game *game, float ray_angle, float *dist);
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
void    render_door_line(t_game *game);
void    open_close_door(t_game *game);
bool    is_collision_point_enemy(t_raycaster *raycaster, t_game *game);
void    set_ray_direction(t_raycaster *raycaster, t_game *game, int *direction);
void    save_closest_distance(float dist, float *prev_dist, float *closest_dist);
void    render_enemy_line(t_game *game);
int     mouse_press(int button, int x, int y, t_game *game);
void	render_hp(t_game *game);
void	render_game_over(t_game *game);
void	render_background(t_game *game);
void    render_minimap_bg(t_game *game);
void    render_minimap_border(t_game *game);

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
// void    		init_game(t_game *game);
void            init_game(t_game *game);
void    		init_keys(t_game *game);

#endif