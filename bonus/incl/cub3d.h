/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:16:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/05 02:21:15 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"
# include "../libs/mlx_linux/mlx.h"
# include "color.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

// screen
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 900
# define DRAWING_SCALE 180000
# define FIELD_OF_VIEW 60.0f
# define MINIMAP_SCALE 20
# define MINIMAP_SIZE 200
# define MINIMAP_SIZE_SQUARES 10
# define TEXTURE_SIZE_AVATAR 300
# define SIZE_AVATAR 250
# define TEXTURE_SIZE_MINIMAP 20
# define TEXTURE_SIZE_DEFAULT 500
# define SQUARE_SIZE 100
# define BORDER_THICKNESS 5
# define TEXTURE_HEIGHT_HP 77
# define TEXTURE_WIDTH_HP 120
# define SIZE_GUN 300
# define TEXTURE_SIZE_GUN 300
# define TEXTURE_MENU_WIDTH 1600
# define TEXTURE_MENU_HEIGHT 900

// objects
# define DEPTH_MAX 30
# define DOOR_MAX 30
# define ENEMY_MAX 30

// players
# define PABECKHA 0
# define SFRANKIE 1

// textures
# define PLAYER_TEXTURE "./bonus/textures/minimap/player_ln_texture.xpm"
# define DOOR_MINIMAP "./bonus/textures/minimap/door.xpm"
# define SKULL "./bonus/textures/minimap/skull.xpm"
# define DESERT_EAGLE_0_4 "./bonus/textures/guns/deagle/deagle_0_4.xpm"
# define DESERT_EAGLE_1_4 "./bonus/textures/guns/deagle/deagle_1_4.xpm"
# define DESERT_EAGLE_2_4 "./bonus/textures/guns/deagle/deagle_2_4.xpm"
# define DESERT_EAGLE_3_4 "./bonus/textures/guns/deagle/deagle_3_4.xpm"
# define DESERT_EAGLE_4_4 "./bonus/textures/guns/deagle/deagle_4_4.xpm"
# define DESERT_EAGLE_RUN_0_1 "./bonus/textures/guns/deagle/deagle_run_0_1.xpm"
# define DESERT_EAGLE_RUN_1_1 "./bonus/textures/guns/deagle/deagle_run_1_1.xpm"
# define SHOTGUN_0_14 "./bonus/textures/guns/shotgun/shotgun_0_14.xpm"
# define SHOTGUN_1_14 "./bonus/textures/guns/shotgun/shotgun_1_14.xpm"
# define SHOTGUN_2_14 "./bonus/textures/guns/shotgun/shotgun_2_14.xpm"
# define SHOTGUN_3_14 "./bonus/textures/guns/shotgun/shotgun_3_14.xpm"
# define SHOTGUN_4_14 "./bonus/textures/guns/shotgun/shotgun_4_14.xpm"
# define SHOTGUN_5_14 "./bonus/textures/guns/shotgun/shotgun_5_14.xpm"
# define SHOTGUN_6_14 "./bonus/textures/guns/shotgun/shotgun_6_14.xpm"
# define SHOTGUN_7_14 "./bonus/textures/guns/shotgun/shotgun_7_14.xpm"
# define SHOTGUN_8_14 "./bonus/textures/guns/shotgun/shotgun_8_14.xpm"
# define SHOTGUN_9_14 "./bonus/textures/guns/shotgun/shotgun_9_14.xpm"
# define SHOTGUN_10_14 "./bonus/textures/guns/shotgun/shotgun_10_14.xpm"
# define SHOTGUN_11_14 "./bonus/textures/guns/shotgun/shotgun_11_14.xpm"
# define SHOTGUN_12_14 "./bonus/textures/guns/shotgun/shotgun_12_14.xpm"
# define SHOTGUN_13_14 "./bonus/textures/guns/shotgun/shotgun_13_14.xpm"
# define SHOTGUN_14_14 "./bonus/textures/guns/shotgun/shotgun_14_14.xpm"
# define SHOTGUN_RUN_0_1 "./bonus/textures/guns/shotgun/shotgun_run_0_1.xpm"
# define SHOTGUN_RUN_1_1 "./bonus/textures/guns/shotgun/shotgun_run_1_1.xpm"
# define DOOR_FRAME_4_4 "./bonus/textures/door/door_frame_4_4.xpm"
# define DOOR_FRAME_3_4 "./bonus/textures/door/door_frame_3_4.xpm"
# define DOOR_FRAME_2_4 "./bonus/textures/door/door_frame_2_4.xpm"
# define DOOR_FRAME_1_4 "./bonus/textures/door/door_frame_1_4.xpm"
# define DOOR_FRAME_0_4 "./bonus/textures/door/door_frame_0_4.xpm"
# define EXIT_4_4 "./bonus/textures/door/exit_4_4.xpm"
# define EXIT_3_4 "./bonus/textures/door/exit_3_4.xpm"
# define EXIT_2_4 "./bonus/textures/door/exit_2_4.xpm"
# define EXIT_1_4 "./bonus/textures/door/exit_1_4.xpm"
# define EXIT_0_4 "./bonus/textures/door/exit_0_4.xpm"
# define DARK_PRIEST_0_9 "./bonus/textures/enemies/dark_priest_0_9.xpm"
# define DARK_PRIEST_1_9 "./bonus/textures/enemies/dark_priest_1_9.xpm"
# define DARK_PRIEST_2_9 "./bonus/textures/enemies/dark_priest_2_9.xpm"
# define DARK_PRIEST_3_9 "./bonus/textures/enemies/dark_priest_3_9.xpm"
# define DARK_PRIEST_4_9 "./bonus/textures/enemies/dark_priest_4_9.xpm"
# define DARK_PRIEST_5_9 "./bonus/textures/enemies/dark_priest_5_9.xpm"
# define DARK_PRIEST_6_9 "./bonus/textures/enemies/dark_priest_6_9.xpm"
# define DARK_PRIEST_7_9 "./bonus/textures/enemies/dark_priest_7_9.xpm"
# define DARK_PRIEST_8_9 "./bonus/textures/enemies/dark_priest_8_9.xpm"
# define DARK_PRIEST_9_9 "./bonus/textures/enemies/dark_priest_9_9.xpm"
# define DARK_PRIEST_CORPSE "./bonus/textures/enemies/dark_priest_corpse.xpm"
# define HP_0 "./bonus/textures/hp/0.xpm"
# define HP_10 "./bonus/textures/hp/10.xpm"
# define HP_20 "./bonus/textures/hp/20.xpm"
# define HP_30 "./bonus/textures/hp/30.xpm"
# define HP_40 "./bonus/textures/hp/40.xpm"
# define HP_50 "./bonus/textures/hp/50.xpm"
# define HP_60 "./bonus/textures/hp/60.xpm"
# define HP_70 "./bonus/textures/hp/70.xpm"
# define HP_80 "./bonus/textures/hp/80.xpm"
# define HP_90 "./bonus/textures/hp/90.xpm"
# define HP_100 "./bonus/textures/hp/100.xpm"
# define GAME_OVER "./bonus/textures/menu/you_died.xpm"
# define WIN_SCREEN "./bonus/textures/menu/you_win.xpm"
# define BLOOD_0_29 "./bonus/textures/blood/1_0.xpm"
# define BLOOD_1_29 "./bonus/textures/blood/1_1.xpm"
# define BLOOD_2_29 "./bonus/textures/blood/1_2.xpm"
# define BLOOD_3_29 "./bonus/textures/blood/1_3.xpm"
# define BLOOD_4_29 "./bonus/textures/blood/1_4.xpm"
# define BLOOD_5_29 "./bonus/textures/blood/1_5.xpm"
# define BLOOD_6_29 "./bonus/textures/blood/1_6.xpm"
# define BLOOD_7_29 "./bonus/textures/blood/1_7.xpm"
# define BLOOD_8_29 "./bonus/textures/blood/1_8.xpm"
# define BLOOD_9_29 "./bonus/textures/blood/1_9.xpm"
# define BLOOD_10_29 "./bonus/textures/blood/1_10.xpm"
# define BLOOD_11_29 "./bonus/textures/blood/1_11.xpm"
# define BLOOD_12_29 "./bonus/textures/blood/1_12.xpm"
# define BLOOD_13_29 "./bonus/textures/blood/1_13.xpm"
# define BLOOD_14_29 "./bonus/textures/blood/1_14.xpm"
# define BLOOD_15_29 "./bonus/textures/blood/1_15.xpm"
# define BLOOD_16_29 "./bonus/textures/blood/1_16.xpm"
# define BLOOD_17_29 "./bonus/textures/blood/1_17.xpm"
# define BLOOD_18_29 "./bonus/textures/blood/1_18.xpm"
# define BLOOD_19_29 "./bonus/textures/blood/1_19.xpm"
# define BLOOD_20_29 "./bonus/textures/blood/1_20.xpm"
# define BLOOD_21_29 "./bonus/textures/blood/1_21.xpm"
# define BLOOD_22_29 "./bonus/textures/blood/1_22.xpm"
# define BLOOD_23_29 "./bonus/textures/blood/1_23.xpm"
# define BLOOD_24_29 "./bonus/textures/blood/1_24.xpm"
# define BLOOD_25_29 "./bonus/textures/blood/1_25.xpm"
# define BLOOD_26_29 "./bonus/textures/blood/1_26.xpm"
# define BLOOD_27_29 "./bonus/textures/blood/1_27.xpm"
# define BLOOD_28_29 "./bonus/textures/blood/1_28.xpm"
# define BLOOD_29_29 "./bonus/textures/blood/1_29.xpm"
# define AVATAR_SZYMON_0_1 "./bonus/textures/player/szymon_0_1.xpm"
# define AVATAR_SZYMON_1_1 "./bonus/textures/player/szymon_1_1.xpm"
# define AVATAR_PAULO_0_1 "./bonus/textures/player/paulo_0_1.xpm"
# define AVATAR_PAULO_1_1 "./bonus/textures/player/paulo_1_1.xpm"
# define MAIN_MENU_PABECKHA "./bonus/textures/menu/pabeckha.xpm"
# define MAIN_MENU_SFRANKIE "./bonus/textures/menu/sfrankie.xpm"

// vectors
# define ANGLE_MAX 360
# define MOVEMENT_SPEED 10
# define ROTATION_SPEED 3
# define DOOR_OPEN_DISTANCE 170

// wall_directions
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

// keys
# define NUM_KEYS 10
# define ESC 0
# define W 1
# define S 2
# define A 3
# define D 4
# define LEFT_ARROW 5
# define RIGHT_ARROW 6
# define E 7
# define MOUSE_LEFT_CLICK 8
# define ENTER 9

// animation
# define DOOR_FRAMES 5
# define DOOR_FRAME_DURATION 1200000
# define ENEMY_FRAMES 11
# define ENEMY_FRAME_DURATION 1550000
# define DESERT_EAGLE_FRAMES 5
# define DESERT_EAGLE_FRAME_DURATION 600000
# define SHOTGUN_FRAMES 15
# define SHOTGUN_FRAME_DURATION 1300000
# define GUN_RUN_FRAMES 2
# define GUN_RUN_FRAME_DURATION 1800000
# define BLOOD_FRAMES 30
# define BLOOD_FRAME_DURATION 600000
# define AVATAR_FRAMES 15
# define AVATAR_FRAME_DURATION 3000000
# define HP_FRAMES 11

typedef struct s_minimap
{
	int			screen_x;
	int			screen_y;
	int			map_x;
	int			map_y;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_minimap;

typedef struct s_render
{
	int			line_height;
	int			y_iterator;
	int			y_end;
	int			tex_x;
	int			tex_y;
	int			color;
	float		scale;
}				t_render;

typedef struct s_image
{
	void		*img;
	int			*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_vectors
{
	float		x;
	float		y;
}				t_vectors;

typedef struct s_textures
{
	void		*north_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
	void		*door_minimap;
	void		*skull;
	void		*player_texture;
	void		*desert_eagle[DESERT_EAGLE_FRAMES];
	void		*desert_eagle_run[GUN_RUN_FRAMES];
	void		*shotgun[SHOTGUN_FRAMES];
	void		*shotgun_run[GUN_RUN_FRAMES];
	void		*gun_current_texture;
	void		*door_texture[DOOR_FRAMES];
	void		*exit[DOOR_FRAMES];
	void		*dark_priest_texture[ENEMY_FRAMES];
	void		*dark_priest_current_texture;
	void		*hp_texture[HP_FRAMES];
	void		*hp_current_texture;
	void		*game_over_texture;
	void		*win_screen;
	void		*blood[BLOOD_FRAMES];
	void		*avatar[4];
	void		*avatar_current;
	void		*main_menu[2];
	void		*main_menu_current;
}				t_textures;

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
}				t_obj;

typedef struct s_depth
{
	float		dist;
	t_obj		obj;
	float		ray_hit_x;
	float		ray_hit_y;
	int			colis_y;
	int			colis_x;
}				t_depth;

typedef struct s_door
{
	void		*texture;
	float		dist;
	int			x;
	int			y;
}				t_door;

typedef struct s_enemy
{
	void		*texture;
	int			x;
	int			y;
	int			x_start;
	int			x_end;
	int			size;
	float		tex_x;
	bool		visible;
	bool		hit_body[SCREEN_WIDTH];
	bool		dead;
}				t_enemy;

typedef struct s_raycaster
{
	float		dir_x;
	float		dir_y;
	float		len;
	float		x_iterator;
	float		y_iterator;
	float		speed;
	float		colis_x;
	float		colis_y;
	int			prev_colis_x;
	int			prev_colis_y;
	bool		found_wall;
}				t_raycaster;

typedef struct s_animation
{
	bool		door_are_opening;
	bool		door_are_closing;
	bool		hp_frame_updated;
	bool		animation_gun;

}				t_animation;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	float		ray_main_angle;
	float		ray_hit_x;
	float		ray_hit_y;
	float		ray_new_x;
	float		ray_new_y;
	int			dist_idx;
	int			depth_lvl;
	int			wall_direction;
	int			door_direction;
	int			img_x;
	int			img_y;
	int			vec_idx;
	float		prev_door_distance;
	int			mouse_x;
	bool		player_dead;
	bool		enemy_visible;
	bool		main_menu;
	int			enemy_count;
	bool		won_game;
	int			player;
	bool		keys[NUM_KEYS];
	t_image		image;
	t_depth		depth[DEPTH_MAX];
	t_vectors	vectors[ANGLE_MAX / ROTATION_SPEED];
	t_textures	textures;
	t_data		data;
	t_door		door[DOOR_MAX];
	t_enemy		enemy[ENEMY_MAX];
	t_animation	animation;
}				t_game;

void			calc_dir_vectors(t_game *game);
void			raycaster(t_game *game);
void			render_game(t_game *game);
void			render_minimap(t_game *game);
void			render_minimap_player(t_game *game);
void			render_gun(t_game *game);
void			render_crosshair(t_game *game);
void			render_wall_line(t_game *game);
void			cast_ray(t_game *game, float ray_angle);
void			load_images_from_dir(t_game *game);

float			to_radians(float degrees);
void			init_raycaster_data(t_raycaster *raycaster, t_game *game,
					float ray_new_x, float ray_new_y);
bool			is_ray_on_square_edge(t_raycaster *raycaster);
void			calc_collision_point_x_y(t_raycaster *raycaster);
bool			is_collision_point_wall(t_raycaster *raycaster, t_game *game);
void			calc_ray_distance(t_raycaster *raycaster, t_game *game,
					float ray_angle, float *dist);
int				get_pixel_color(void *img_ptr, int x, int y);

// key_actions.c
int				close_game(t_game *game);
void			init_hooks(t_game *game);
int				keypress(int keysymbol, t_game *game);
int				keyrelease(const int keysymbol, t_game *game);
int				mouse_move(int x, int y, t_game *game);
int				loop_hook(t_game *game);
void			rotate_player_left(t_game *game);
void			rotate_player_right(t_game *game);
void			move_player_backward(t_game *game);
void			move_player_forward(t_game *game);
void			move_player_left(t_game *game);
void			move_player_right(t_game *game);

void			render_door_line(t_game *game);
void			open_close_door(t_game *game);
bool			is_collision_point_enemy(t_raycaster *raycaster, t_game *game);
void			set_ray_direction(t_raycaster *raycaster, int *direction);
void			save_closest_distance(t_raycaster *raycaster, t_game *game);
void			render_enemy_line(t_game *game, int enemy_i);
int				mouse_press(int button, int x, int y, t_game *game);
void			render_hp(t_game *game);
void			render_background(t_game *game);
void			render_minimap_bg(t_game *game);
void			render_border(t_game *game, int size, int x, int y);
bool			is_collision_point_door(t_raycaster *raycaster, t_game *game);
int				find_enemy_end(t_game *game, float angle_iter, int enemy_i);
int				cast_ray_till_enemy(t_game *game, float ray_new_x,
					float ray_new_y, int enemy_i);
int				find_enemy_start(t_game *game, float angle_iter, int enemy_i);
void			action_mouse_left_click(t_game *game);
void			animation_enemy_cast(t_game *game);
void			animation_close_door(t_game *game);
void			animation_open_door(t_game *game);
void			rotate_player_mouse(t_game *game);
void			animation_enemy_death(t_game *game);
void			render_avatar(t_game *game);
void			animation_avatar(t_game *game);
void			render_main_menu(t_game *game);
void			animation_gun_running(t_game *game);
void			animation_gun_shoot(t_game *game, int frame_duration,
					int frames, void **gun_type);
void			action_main_menu(t_game *game);
void			action_game(t_game *game);
void			animation(t_game *game);
void			update_enemy_cast_textures(t_game *game, int j);
void			update_hp_status(t_game *game, int enemy_frame);
void			update_door_close_textures(t_game *game, int door_frame);
void			update_door_open_textures(t_game *game, int door_frame);
void			update_avatar_textures(t_game *game, int avatar_frame);
void			update_gun_running_textures(t_game *game, int gun_frame);
void			update_death_textures(t_game *game, int j);
void			change_door_state(t_game *game, int i);
void			load_images_wall(t_game *game);
void			load_images_minimap(t_game *game);
void			load_images_desert_eagle(t_game *game);
void			load_images_shotgun_1_2(t_game *game);
void			load_images_shotgun_2_2(t_game *game);
void			load_images_door(t_game *game);
void			load_images_enemy_1_2(t_game *game);
void			load_images_enemy_2_2(t_game *game);
void			load_images_hp(t_game *game);
void			load_images_blood_1_3(t_game *game);
void			load_images_blood_2_3(t_game *game);
void			load_images_blood_3_3(t_game *game);
void			load_images_menu(t_game *game);
void			load_images_avatar(t_game *game);
void			reset_objects_data(t_game *game);
void			reset_depth_data(t_game *game);
void			render_vertical(t_game *game);
float			fix_angle_overflow(float angle_iter);
int				find_enemy(t_game *game);
bool			is_ray_out_of_map(t_raycaster *raycaster, t_game *game);
bool			is_direction_in_range(t_raycaster *raycaster, t_game *game);
void			save_object_wall(t_raycaster *raycaster, t_game *game,
					float ray_angle);
void			save_object_door(t_raycaster *raycaster, t_game *game,
					float ray_angle);
void			save_object_enemy(t_raycaster *raycaster, t_game *game,
					float ray_angle);
bool			is_coll_point_same(t_raycaster *raycaster);
void			calc_enemy_data_relative_to_player(t_game *game,
					float ray_angle, int i);
void			render_minimap_horizontal_pixels(t_game *game,
					t_minimap *minimap);
void			render_wall_pixels_vertical(t_game *game, t_render *render);
void			render_door_pixels_vertical(t_game *game, t_render *render);
void			render_door_pixels_vertical(t_game *game, t_render *render);
void			render_enemy_pixels_vertical(t_game *game, int enemy_i, int y,
					int y_end);
void			render_main_menu_pixels_vertical(t_game *game, float tex_x,
					int x);
void			init_mlx(t_game *game);
void			init_utils(t_game *game);
void			assign_door_texture(t_game *game, int x, int y, int i);
void			init_image(t_game *game);

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
int				parser(char *str, t_data *data);
void			replace_error_message(t_data *data, char *str);
int				rgb_to_hex(int red, int green, int blue);
int				size_array(char **array);
bool			store_cub_file(t_data *data, char *str);
bool			store_hex_color(char *str, t_data *data, char surf);
bool			store_textures(t_data *data);
bool			store_surface_colors(t_data *data);
bool			store_map(t_data *data);
void			init_game(t_game *game);
void			init_vars_colors(int *red, int *green, int *blue);
bool			get_red_color(int *red, char **array, t_data *data);
bool			get_green_color(int *green, char **array, t_data *data);
bool			get_blue_color(int *blue, char **array, t_data *data);
bool			check_error_rgb_format(int color, t_data *data);
bool			check_if_empty_line(char *str);
bool			check_edges(int i, int j, t_data *data);
void			init_vars_check_wall(int *i, int *j);
bool			return_error_wall(t_data *data);
bool			check_first_line(int i, int j, t_data *data);
bool			check_last_line(int i, int j, t_data *data);
bool			check_input_texture(t_data *data);
bool			check_map_last_element(t_data *data);
bool			check_map_element_input(t_data *data);
bool			check_empty_line_map(t_data *data);
void			store_first_line_map_element(t_data *data);
void			store_last_line_map_element(t_data *data);
bool			check_other_values_rgb(char *cleaned_string, t_data *data);
bool			check_surround(t_data *data);
bool			store_north_texture_format(t_data *data, char **array);
bool			store_south_texture_format(t_data *data, char **array);
bool			store_west_texture_format(t_data *data, char **array);
bool			store_east_texture_format(t_data *data, char **array);
bool			apply_ffill_algo(char **map_backup, t_data *data);
void			print_arg_error(void);

#endif