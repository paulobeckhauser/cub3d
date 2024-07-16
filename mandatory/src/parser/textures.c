/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 12:35:28 by pabeckha         ###   ########.fr       */
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

bool	check_open_texture_files(t_data *data)
{
	int	fd_north;
	int	fd_south;
	int	fd_west;
	int	fd_east;

	fd_north = open(data->texture_north, O_RDONLY);
	fd_south = open(data->texture_south, O_RDONLY);
	fd_west = open(data->texture_west, O_RDONLY);
	fd_east = open(data->texture_east, O_RDONLY);
	if (fd_north == -1 || fd_south == -1 || fd_west == -1 || fd_east == -1)
	{
		replace_error_message(data, "One or more texture file does not exist");
		close(fd_north);
		close(fd_south);
		close(fd_west);
		close(fd_east);
		return (false);
	}
	close(fd_north);
	close(fd_south);
	close(fd_west);
	close(fd_east);
	return (true);
}

bool	store_textures(t_data *data)
{
	if (!check_storage_textures(data) || !check_input_texture(data)
		|| !check_open_texture_files(data))
		return (false);
	return (true);
}
