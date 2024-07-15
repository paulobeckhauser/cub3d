/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:26:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_if_map_element(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'W' || str[i] == 'E' || (str[i] >= 9
				&& str[i] <= 13))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_if_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			return (false);
	}
	return (true);
}

void	store_first_line_map_element(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (check_if_map_element(data->cub_file[i])
			&& !check_if_empty_line(data->cub_file[i]))
		{
			data->line_start_map_position = i;
			break ;
		}
		i++;
	}
}

void	store_last_line_map_element(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	while (data->cub_file[i])
	{
		if (check_if_empty_line(data->cub_file[i]))
		{
			data->line_end_map_position = i - 1;
			break ;
		}
		i++;
	}
	data->line_end_map_position = i - 1;
}

bool	store_map_element(t_data *data)
{
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
		i++;
		j++;
	}
	data->map_element[j] = NULL;
	return (true);
}

bool	check_map_last_element(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->line_end_map_position + 1;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (data->cub_file[i][j] != ' ')
			{
				replace_error_message(data, "Map element in wrong format");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_element_input(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = data->line_start_map_position + 1;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (data->cub_file[i][j] != '0' && data->cub_file[i][j] != '1'
				&& data->cub_file[i][j] != ' ' && data->cub_file[i][j] != 'N'
				&& data->cub_file[i][j] != 'S' && data->cub_file[i][j] != 'E'
				&& data->cub_file[i][j] != 'W' && (data->cub_file[i][j] < 9
					|| data->cub_file[i][j] > 13))
			{
				replace_error_message(data, "Map element in wrong format");
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_empty_line_map(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	while (i < data->line_end_map_position)
	{
		if (check_if_empty_line(data->cub_file[i]))
		{
			replace_error_message(data, "Map element in wrong format");
			return (false);
		}
		i++;
	}
	return (true);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_element[i])
	{
		printf("%s\n", (data->map_element[i]));
		i++;
	}
}

bool	check_wall(t_data *data)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	j = 0;
	col = 0;
	while (data->map_element[i])
	{
		if (i == 0 || i == size_array(data->map_element) - 1)
		{
			j = 0;
			while (data->map_element[i][j])
			{
				if (data->map_element[i][j] == '1')
				{
					j++;
					continue ;
				}
				else if (data->map_element[i][j] == ' '
					|| (data->map_element[i][j] >= 9
						&& data->map_element[i][j] <= 13))
				{
					if (i == 0)
					{
						col = i;
						while (data->map_element[col][j])
						{
							if (data->map_element[col][j] == '1')
								break ;
							else if (data->map_element[col][j] == ' ')
							{
								col++;
								continue ;
							}
							else
							{
								replace_error_message(data,
									"Map not surrounded by walls");
								return (false);
							}
							col++;
						}
					}
					if (i == size_array(data->map_element) - 1)
					{
						col = i;
						while (data->map_element[col][j])
						{
							if (data->map_element[col][j] == '1')
								break ;
							else if (data->map_element[col][j] == ' ')
							{
								col--;
								continue ;
							}
							else
							{
								replace_error_message(data,
									"Map not surrounded by walls");
								return (false);
							}
							col--;
						}
					}
				}
				else
				{
					replace_error_message(data, "Map not surrounded by walls");
					return (false);
				}
				j++;
			}
		}
		i++;
	}
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

	map_backup = malloc((size_array(data->map_element) + 1) * sizeof(char *));
	i = 0;
	while (data->map_element[i])
	{
		map_backup[i] = ft_strdup(data->map_element[i]);
		i++;
	}
	map_backup[i] = NULL;
	all_surrounded = true;
	i = 0;
	j = 0;
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
