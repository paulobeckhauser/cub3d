/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/21 18:01:13 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	init_vars_check_wall(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

bool	check_edges(int i, int j, t_data *data)
{
	if (i == 0 && check_first_line(i, j, data))
		return (true);
	if ((i == size_array(data->map_element) - 1) && (check_last_line(i, j,
				data)))
		return (true);
	return (false);
}

bool	return_error_wall(t_data *data)
{
	replace_error_message(data, "Map not surrounded by walls");
	return (false);
}

static bool	write_map_lines(char **map_backup, t_data *data)
{
	int	i;

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
	return (true);
}

bool	check_surround(t_data *data)
{
	char	**map_backup;

	map_backup = malloc((size_array(data->map_element) + 1) * sizeof(char *));
	if (!map_backup)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	if (!write_map_lines(map_backup, data) || !apply_ffill_algo(map_backup,
			data))
	{
		free_2d_array(map_backup);
		return (false);
	}
	free_2d_array(map_backup);
	return (true);
}
