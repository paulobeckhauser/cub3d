/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/21 17:57:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

static bool	allocate_map_element(t_data *data)
{
	data->number_lines_map_element = data->line_end_map_position
		- data->line_start_map_position + 1;
	data->map_element = malloc((data->number_lines_map_element + 1)
			* sizeof(char *));
	if (!data->map_element)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	return (true);
}

static bool	store_lines_map(t_data *data, int i)
{
	int	j;

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

bool	store_map_element(t_data *data)
{
	int	i;

	i = data->line_start_map_position;
	if (!allocate_map_element(data))
		return (false);
	if (!data->map_element)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	if (!store_lines_map(data, i))
		return (false);
	return (true);
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
