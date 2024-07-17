/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:08:00 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/17 15:29:57 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_garbage_values_map(t_data *data)
{
	int		i;
	char	**array;

	i = 0;
	array = NULL;
	while (data->cub_file[i] && i < data->line_start_map_position)
	{
		array = ft_split(data->cub_file[i], ' ');
		if (array[0] == NULL || ft_strcmp(array[0], "NO") == 0
			|| ft_strcmp(array[0], "SO") == 0 || ft_strcmp(array[0], "WE") == 0
			|| ft_strcmp(array[0], "EA") == 0 || ft_strcmp(array[0], "F") == 0
			|| ft_strcmp(array[0], "C") == 0)
			free_2d_array(array);
		else
		{
			free_2d_array(array);
			return (replace_error_message(data, "Irrelevant data in map"),
				false);
		}
		i++;
	}
	return (true);
}

int	parser(char *str, t_data *data)
{
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
	{
		replace_error_message(data, "Memory allocation failed");
		return (free_variables_error(data));
	}
	init_vars(data);
	if (!check_extension(data, str, "cub") || !store_cub_file(data, str)
		|| !store_surface_colors(data) || !store_textures(data)
		|| !store_map(data) || !check_garbage_values_map(data))
		return (free_variables_error(data));
	return (0);
}
