/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 20:38:40 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	store_map_element(t_data *data)
{
	int	i;
	int	j;

	i = data->line_start_map_position;
	data->number_lines_map_element = data->line_end_map_position
		- data->line_start_map_position + 1;
	data->map_element = malloc((data->number_lines_map_element + 1)
			* sizeof(char *));
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

bool	check_surround(t_data *data)
{
	int		i;
	char	**map_backup;
	bool	all_surrounded;

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
	all_surrounded = apply_ffill_algo(map_backup, data);
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
