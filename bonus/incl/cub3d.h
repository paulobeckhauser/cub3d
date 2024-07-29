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
#define MINIMAP_SCALE (SCREEN_WIDTH / 80)
#define MINIMAP_SIZE (SCREEN_WIDTH / 8)
#define MINIMAP_SIZE_SQUARES 10
#define TEXTURE_SIZE_AVATAR 300
#define SIZE_AVATAR 250
#define TEXTURE_SIZE_MINIMAP 20
#define TEXTURE_SIZE_DEFAULT 500
#define SQUARE_SIZE 100
#define BORDER_THICKNESS 5
#define TEXTURE_HEIGHT_HP 77
#define TEXTURE_WIDTH_HP 120

// objects
#define DEPTH_MAX 30
#define DOOR_MAX 30
#define ENEMY_MAX 30

// textures
#define MINIMAP_BG "./bonus/textures/minimap/minimap_bg.xpm"
#define FLOOR_TEXTURE "./bonus/textures/minimap/floor_texture.xpm"
#define WALL_TEXTURE "./bonus/textures/minimap/wall_texture.xpm"
#define PLAYER_TEXTURE "./bonus/textures/minimap/player_ln_texture.xpm"
#define DOOR_MINIMAP "./bonus/textures/minimap/door.xpm"
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
#define DARK_PRIEST_CORPSE "./bonus/textures/enemies/dark_priest_corpse.xpm"
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
#define BLOOD_0_29 "./bonus/textures/blood/1_0.xpm"
#define BLOOD_1_29 "./bonus/textures/blood/1_1.xpm"
#define BLOOD_2_29 "./bonus/textures/blood/1_2.xpm"
#define BLOOD_3_29 "./bonus/textures/blood/1_3.xpm"
#define BLOOD_4_29 "./bonus/textures/blood/1_4.xpm"
#define BLOOD_5_29 "./bonus/textures/blood/1_5.xpm"
#define BLOOD_6_29 "./bonus/textures/blood/1_6.xpm"
#define BLOOD_7_29 "./bonus/textures/blood/1_7.xpm"
#define BLOOD_8_29 "./bonus/textures/blood/1_8.xpm"
#define BLOOD_9_29 "./bonus/textures/blood/1_9.xpm"
#define BLOOD_10_29 "./bonus/textures/blood/1_10.xpm"
#define BLOOD_11_29 "./bonus/textures/blood/1_11.xpm"
#define BLOOD_12_29 "./bonus/textures/blood/1_12.xpm"
#define BLOOD_13_29 "./bonus/textures/blood/1_13.xpm"
#define BLOOD_14_29 "./bonus/textures/blood/1_14.xpm"
#define BLOOD_15_29 "./bonus/textures/blood/1_15.xpm"
#define BLOOD_16_29 "./bonus/textures/blood/1_16.xpm"
#define BLOOD_17_29 "./bonus/textures/blood/1_17.xpm"
#define BLOOD_18_29 "./bonus/textures/blood/1_18.xpm"
#define BLOOD_19_29 "./bonus/textures/blood/1_19.xpm"
#define BLOOD_20_29 "./bonus/textures/blood/1_20.xpm"
#define BLOOD_21_29 "./bonus/textures/blood/1_21.xpm"
#define BLOOD_22_29 "./bonus/textures/blood/1_22.xpm"
#define BLOOD_23_29 "./bonus/textures/blood/1_23.xpm"
#define BLOOD_24_29 "./bonus/textures/blood/1_24.xpm"
#define BLOOD_25_29 "./bonus/textures/blood/1_25.xpm"
#define BLOOD_26_29 "./bonus/textures/blood/1_26.xpm"
#define BLOOD_27_29 "./bonus/textures/blood/1_27.xpm"
#define BLOOD_28_29 "./bonus/textures/blood/1_28.xpm"
#define BLOOD_29_29 "./bonus/textures/blood/1_29.xpm"
#define AVATAR_SZYMON_0_1 "./bonus/textures/player/szymon_0_1.xpm"
#define AVATAR_SZYMON_1_1 "./bonus/textures/player/szymon_1_1.xpm"
#define AVATAR_PAULO_0_1 "./bonus/textures/player/paulo_0_1.xpm"
#define AVATAR_PAULO_1_1 "./bonus/textures/player/paulo_1_1.xpm"
#define MAIN_MENU_PABECKHA "./bonus/textures/menu/pabeckha.xpm"
#define MAIN_MENU_SFRANKIE "./bonus/textures/menu/sfrankie.xpm"

// vectors
#define ANGLE_MAX 360
#define MOVEMENT_SPEED 10
#define ROTATION_SPEED 4
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
#define ENTER 9

// animation
#define DOOR_FRAMES 5
#define DOOR_FRAME_DURATION 1200000
#define ENEMY_FRAMES 11
#define ENEMY_FRAME_DURATION 4800000
#define GUN_FRAMES 5
#define GUN_FRAME_DURATION 600000
#define BLOOD_FRAMES 30
#define BLOOD_FRAME_DURATION 2400000
#define AVATAR_FRAMES 15
#define AVATAR_FRAME_DURATION 12000000

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

typedef struct s_textures
{
	void    *north_texture;
	void    *south_texture;
	void    *west_texture;
	void    *east_texture;
	void    *door_minimap;
	void    *skull;
	void	*player_texture;
	void	*gun_texture[5];
	void    *gun_current_texture;
	void	*door_texture[5];
	void    *dark_priest_texture[11];
	void    *dark_priest_current_texture;
	void    *hp_texture[11];
	void    *hp_current_texture;
	void	*game_over_texture;
	void    *blood[30];
	void	*avatar[2];
	void	*avatar_current;
	void    *main_menu[2];
	void    *main_menu_current;
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

typedef enum s_obj
{
	EMPTY,
	WALL,
	DOOR,
	ENEMY,
}   t_obj;

typedef struct s_depth
{
	float   dist;
	t_obj   obj;
	float   ray_hit_x;
	float   ray_hit_y;
	int     colis_y;
	int     colis_x;
}   t_depth;

typedef struct s_door
{
	void    *texture;
	float   dist;
	int     x;
	int     y;
}   t_door;

typedef struct s_enemy
{
	void    *texture;
	int     x;
	int     y;
	int     x_start;
	int     x_end;
	int     size;
	float   tex_x;
	int     depth_lvl;
	bool    visible;
	bool    hit_body[SCREEN_WIDTH];
	bool    got_bullet;
	bool    dead;
}	t_enemy;

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
	int     prev_colis_x;
	int     prev_colis_y;
	bool    found_wall;
	bool    found_enemy;
}   t_raycaster;

typedef struct s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_image *image;
	char	**map;
	float	ray_new_x;
	float	ray_new_y;
	float	ray_main_angle;
	float   ray_hit_x;
	float   ray_hit_y;
	t_depth depth[30];
	int     dist_idx;
	int     depth_lvl;
	int     wall_direction;
	int     door_direction;
	int		enemy_x;
	int		enemy_y;
	int     img_x;
	int     img_y;
	bool    keys[10];
	t_vectors *vectors;
	int     vec_idx;
	long    door_animation_start_time;
	bool    door_are_opening;
	bool    door_are_closing;
	float   prev_door_distance;
	long    enemy_animation_start_time;
	long    gun_animation_start_time;
	bool    hit_enemy;
	bool    enemy_visible;
	int     mouse_x;
	bool	hp_frame_updated;
	bool	player_dead;
	t_textures	*textures;
	t_data  *data;
	int     x_enemy_start;
	int     x_enemy_end;
	t_door  door[DOOR_MAX];
	t_enemy enemy[ENEMY_MAX];
	bool    main_menu;
}	t_game;

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
void    calc_directions(t_raycaster *raycaster, t_game *game, float ray_new_x, float ray_new_y);
bool    is_ray_on_square_edge(t_raycaster *raycaster);
void    calc_collision_point_x_y(t_raycaster *raycaster);
bool    is_collision_point_wall(t_raycaster *raycaster, t_game *game);
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

void    render_door_line(t_game *game);
void    open_close_door(t_game *game);
bool    is_collision_point_enemy(t_raycaster *raycaster, t_game *game);
void    set_ray_direction(t_raycaster *raycaster, int *direction);
void    save_closest_distance(t_raycaster *raycaster, t_game *game);
void    render_enemy_line(t_game *game, int enemy_i);
int     mouse_press(int button, int x, int y, t_game *game);
void	render_hp(t_game *game);
void	render_game_over(t_game *game);
void	render_background(t_game *game);
void    render_minimap_bg(t_game *game);
//void    render_border(t_game *game);
void    render_border(t_game *game, int size, int x, int y);
bool    is_collision_point_door(t_raycaster *raycaster, t_game *game);
int	    find_enemy_end(t_game *game, float angle_iter, int enemy_i);
int     cast_ray_till_enemy(t_game *game, float ray_new_x, float ray_new_y, int enemy_i);
int     find_enemy_start(t_game *game, float angle_iter, int enemy_i);
void    action_mouse_left_click(t_game *game);
void    animation_enemy_cast(t_game *game);
void    animation_close_door(t_game *game);
void    animation_open_door(t_game *game);
void    rotate_player_mouse(t_game *game);
void    animation_enemy_death(t_game *game);
void    render_avatar(t_game *game);
void    animation_avatar(t_game *game);
void    render_main_menu(t_game *game);

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
void			init_vars_colors(int *red, int *green, int *blue);
bool			get_red_color(int *red, char **array, t_data *data);
bool			get_green_color(int *green, char **array, t_data *data);
bool			get_blue_color(int *blue, char **array, t_data *data);
bool	check_error_rgb_format(int color, t_data *data, char **array);
bool	check_if_empty_line(char *str);
bool	check_edges(int i, int j, t_data *data);
void	init_vars_check_wall(int *i, int *j);
bool	return_error_wall(t_data *data);
bool	check_first_line(int i, int j, t_data *data);
bool	check_last_line(int i, int j, t_data *data);
bool	check_input_texture(t_data *data);
bool	check_map_last_element(t_data *data);
bool	check_map_element_input(t_data *data);
bool	check_empty_line_map(t_data *data);
void	store_first_line_map_element(t_data *data);
void	store_last_line_map_element(t_data *data);

// DELETE IT AFTER DELETE IT AFTER DELETE IT AFTER DELETE IT AFTER DELETE IT AFTER DELETE IT AFTER
void    render_vertical_line(int x, t_game *game, int red, int green, int blue);

#endif