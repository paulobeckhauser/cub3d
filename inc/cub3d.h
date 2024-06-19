/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:21:57 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/19 14:55:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"
# include "../libs/mlx_linux/mlx.h"

# include "color.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>


typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_player
{
	char	direction;
	int		x;
	int		y;
}	t_player;

typedef struct s_data
{
	char		**cub_file;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			n_text_count;
	int			s_text_count;
	int			w_text_count;
	int			e_text_count;
	// int			f_surf_count;
	int			c_surf_count;
	int			number_lines_map;
	int			floor_color;
	int 		ceiling_color_count;
	int 		floor_color_count;
	bool		floor_color_exist;
	int			ceiling_color;
	bool		ceiling_color_exist;
	char		**map_element;
	// char 		**map_element_check;
	int			number_lines_map_element;
	bool		map_error;
	char		*map_error_message;
	int			element_position;
	int			line_start_map_position;
	int			line_end_map_position;
	bool		map_correct_position;
	t_player	*player;
}	t_data;

void	init_vars(t_data *data);
int		parser(char *str);
void	free_2d_array(char **array);
int		rgb_to_hex(int red, int green, int blue);
// int		store_hex_color(char *line);
char	*trim_rgb_input(char *str, char digit);
bool	color_input_exist(char *str, char digit);
int		size_array(char **array);
bool	rgb_correct_format(char *str, char digit);
bool	checker_surfaces_colors(t_data *data, char *str, char digit);
bool	store_surfaces_colors(char *line, t_data *data);
bool	store_texture_images(char *line, t_data *data);
bool	store_cub_file(t_data *data, char *str);
bool	check_input_floor_texture_exist(t_data *data);
bool	count_lines_map(t_data *data, char *str);
int		free_variables_error(t_data *data);
bool	check_map_content_last_element(t_data *data);
bool	size_map_element(t_data *data);
bool	check_empty_line(char *str);
bool	check_map_element(char *str);
// bool	store_map_element(t_data *data);
bool	check_walls_in_edges(t_data *data);
void	replace_error_message(t_data *data, char *str);
// bool	check_extension(t_data *data, char *str);
bool 	check_extension(t_data *data, char *str, char *extension);
void	get_map_elem_info(t_data *data);
bool	new_checker_borders(t_data *data);
void	print_returned_map(t_data *data);
bool	check_floor_texture_format(t_data *data);
bool	check_player(t_data *data);
bool 	check_player_dir(char c);
void 	replace_player_for_floor(t_data *data, int j);
bool 	check_empty_line_map_element (t_data *data);
// bool 	check_textures(t_data *data);
// bool 	store_textures(t_data *data);
// bool store_floor_surface(t_data *data);
// bool store_hex_color(char *str, t_data *data);


bool store_hex_color(char *str, t_data *data, char surf);
bool 	store_surface_colors(t_data *data);
char *clean_str_color(t_data *data, int i, char surf);
bool clean_store_hex_color(t_data *data, int i, char surf);
bool floor_ceiling_lines(char **array, t_data *data, int i);
bool store_textures(t_data *data);
bool check_xpm_extension(t_data *data, char *str);
bool store_map(t_data *data);
bool check_if_map_element(char *str);

#endif