/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 22:26:42 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	store_map_element(t_data *data)
{
//	int	lines_map;
	int	i;
	int	j;

	i = data->line_start_map_position;
	data->number_lines_map_element = data->line_end_map_position - data->line_start_map_position + 1;
	data->map_element = malloc((data->number_lines_map_element + 1) * sizeof(char *));
	if (!data->map_element)
	{
		replace_error_message(data, "Memory allocation failed");
		return (false);
	}
	j = 0;
	while (i <= data->line_end_map_position)
	{
		data->map_element[j] = ft_strdup(data->cub_file[i]);
		if (!data->map_element[j])
		{
			replace_error_message(data, "Memory allocation failed");
			free_variables_error(data);
			return (false);
		}
		i++;
		j++;
	}
	data->map_element[j] = NULL;
	return (true);
}

static bool	flood_fill(char **map, int x, int y, char target, char new)
{
	size_t	new_y;
	bool	up;
	bool	down;
	bool	right;
	bool	left;

	new_y = (size_t)y;
	if (x < 0 || x >= size_array(map) || y < 0 || new_y >= ft_strlen(map[x]))
		return (false);
	if (map[x][y] == ' ')
		return (false);
	if (map[x][y] != target || map[x][y] == new)
		return (true);
	map[x][y] = new;
	down = flood_fill(map, x + 1, y, target, new);
	up = flood_fill(map, x - 1, y, target, new);
	right = flood_fill(map, x, y + 1, target, new);
	left = flood_fill(map, x, y - 1, target, new);
	return (up && down && right && left);
}

bool	check_surround(t_data *data)
{
	int		i;
	char	**map_backup;
	bool	all_surrounded;
	int		j;

	// i = 0;
	// while(data->map_element[i])
	// {
	//     printf("%s\n", data->map_element[i]);
	//     i++;
	// }
	map_backup = malloc((size_array(data->map_element) + 1) * sizeof(char *));
	i = 0;
	while (data->map_element[i])
	{
		map_backup[i] = ft_strdup(data->map_element[i]);
		if (!map_backup[i])
		{
			replace_error_message(data, "Memory allocation failed");
			free_variables_error(data);
			return (false);
		}
		i++;
	}
	map_backup[i] = NULL;
	all_surrounded = true;
	i = 0;
	j = 0;
	// while(map_backup[i])
	// {
	//     printf("%s\n", map_backup[i]);
	//     // flood_fill(map_backup, i, j, '0', 'X');
	//     i++;
	// }
	while (map_backup[i])
	{
		j = 0;
		while (map_backup[i][j])
		{
			if (map_backup[i][j] == '0')
			{
				if (!flood_fill(map_backup, i, j, '0', 'X'))
				{
					replace_error_message(data, "Map not surrounded");
					all_surrounded = false;
				}
			}
			j++;
		}
		i++;
	}
	free_2d_array(map_backup);
	return (all_surrounded);
}

// static bool	count_player(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	count_player;

// 	i = 0;
// 	j = 0;
// 	count_player = 0;
// 	while (data->map_element[i])
// 	{
// 		j = 0;
// 		while (data->map_element[i][j])
// 		{
// 			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
// 				|| data->map_element[i][j] == 'W'
// 				|| data->map_element[i][j] == 'E')
// 			{
// 				count_player++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (count_player == 0)
// 	{
// 		replace_error_message(data, "No player in the map");
// 		return (false);
// 	}
// 	else if (count_player > 1)
// 	{
// 		replace_error_message(data, "More than one player in the map");
// 		return (false);
// 	}
// 	return (true);
// }

// static void	replace_player_for_floor(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (data->map_element[i])
// 	{
// 		j = 0;
// 		while (data->map_element[i][j])
// 		{
// 			if (data->map_element[i][j] == 'N' || data->map_element[i][j] == 'S'
// 				|| data->map_element[i][j] == 'W'
// 				|| data->map_element[i][j] == 'E')
// 			{
// 				data->player->x = (float)j * 100 + 100 / 2;
// 				data->player->y = (float)i * 100 + 100 / 2;
// 				data->player->direction = data->map_element[i][j];
// 				data->map_element[i][j] = '0';
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

bool	store_map(t_data *data)
{
	store_first_line_map_element(data);
	store_last_line_map_element(data);
	if (!store_map_element(data) || !check_map_last_element(data)
		|| !check_map_element_input(data) || !check_empty_line_map(data)
		|| !check_player(data) || !check_surround(data))
		return (false);
	return (true);
}
