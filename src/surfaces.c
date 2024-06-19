/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:15:35 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/19 20:54:56 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	check_input_surfaces(t_data *data)
{
	if (data->color_floor_count > 1)
	{
		replace_error_message(data, "More than 1 input for floor color");
		return (false);
	}
	else if (data->color_floor_count < 1)
	{
		replace_error_message(data,
			"No input for floor color or in wrong format");
		return (false);
	}
	if (data->color_ceiling_count > 1)
	{
		replace_error_message(data, "More than 1 input for ceiling color");
		return (false);
	}
	else if (data->color_ceiling_count < 1)
	{
		replace_error_message(data,
			"No input for ceiling color or in wrong format");
		return (false);
	}
	return (true);
}

bool	floor_ceiling_lines(char **array, t_data *data, int i)
{
	if (array[0])
	{
		if (ft_strcmp(array[0], "F") == 0)
		{
			if (!clean_store_hex_color(data, i, 'F'))
				return (false);
		}
		else if (ft_strcmp(array[0], "C") == 0)
		{
			if (!clean_store_hex_color(data, i, 'C'))
				return (false);
		}
	}
	return (true);
}

bool	store_surface_colors(t_data *data)
{
	int		i;
	char	**array;

	i = 0;
	array = NULL;
	while (data->cub_file[i])
	{
		array = ft_split(data->cub_file[i], ' ');
		if (!array)
		{
			replace_error_message(data, "Memory allocation failed");
			return (false);
		}
		if (!floor_ceiling_lines(array, data, i))
			return (false);
		free_2d_array(array);
		i++;
	}
	if (!check_input_surfaces(data))
		return (false);	
	return (true);
}
