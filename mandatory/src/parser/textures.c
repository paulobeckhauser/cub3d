/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:14:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	check_xpm_extension(t_data *data, char *str)
{
	char	**array;
	int		i;

	array = NULL;
	array = ft_split(str, '.');
	i = size_array(array) - 1;
	if (array[i])
	{
		if (ft_strcmp(array[i], "xpm") != 0)
		{
			replace_error_message(data,
				"One or more texture not in .xpm format");
			return (false);
		}
	}
	free_2d_array(array);
	return (true);
}

bool	check_storage_textures(t_data *data)
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
		if (array[0])
		{
			if (!store_north_texture_format(data, array)
				|| !store_south_texture_format(data, array)
				|| !store_west_texture_format(data, array)
				|| !store_east_texture_format(data, array))
				return (false);
		}
		i++;
		free_2d_array(array);
	}
	return (true);
}

bool	store_textures(t_data *data)
{
	if (!check_storage_textures(data) || !check_input_texture(data))
		return (false);
	return (true);
}
