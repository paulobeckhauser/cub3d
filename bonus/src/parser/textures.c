/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/01 18:18:49 by pabeckha         ###   ########.fr       */
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

bool	check_input_texture(t_data *data)
{
	if (data->text_count_n > 1)
	{
		replace_error_message(data, "More than 1 input for North Texture");
		return (false);
	}
	else if (data->text_count_n < 1)
	{
		replace_error_message(data,
			"No input for North Texture or in wrong format");
		return (false);
	}
	else if (data->text_count_s > 1)
	{
		replace_error_message(data, "More than 1 input for South Texture");
		return (false);
	}
	else if (data->text_count_s < 1)
	{
		replace_error_message(data,
			"No input for South Texture or in wrong format");
		return (false);
	}
	else if (data->text_count_w > 1)
	{
		replace_error_message(data, "More than 1 input for West Texture");
		return (false);
	}
	else if (data->text_count_w < 1)
	{
		replace_error_message(data,
			"No input for West Texture or in wrong format");
		return (false);
	}
	else if (data->text_count_e > 1)
	{
		replace_error_message(data, "More than 1 input for East Texture");
		return (false);
	}
	else if (data->text_count_e < 1)
	{
		replace_error_message(data,
			"No input for East Texture or in wrong format");
		return (false);
	}
	return (true);
}


bool	store_textures(t_data *data)
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
			if (ft_strcmp(array[0], "NO") == 0)
			{
                // check_north_texture(data, array);
				if (size_array(array) != 2)
				{
					replace_error_message(data, "Texture in wrong format");
					return (false);
				}
				data->text_count_n++;
				if (!array[1])
				{
					replace_error_message(data, "No input for one Texture");
					return (false);
				}
				else if (!check_xpm_extension(data, array[1]))
					return (false);
				else
					data->texture_north = ft_strdup(array[1]);
			}
			else if (ft_strcmp(array[0], "SO") == 0)
			{
				if (size_array(array) != 2)
				{
					replace_error_message(data, "Texture in wrong format");
					return (false);
				}
				data->text_count_s++;
				if (!array[1])
				{
					replace_error_message(data, "No input for one Texture");
					return (false);
				}
				else if (!check_xpm_extension(data, array[1]))
					return (false);
				else
					data->texture_south = ft_strdup(array[1]);
			}
			else if (ft_strcmp(array[0], "WE") == 0)
			{
				if (size_array(array) != 2)
				{
					replace_error_message(data, "Texture in wrong format");
					return (false);
				}
				data->text_count_w++;
				if (!array[1])
				{
					replace_error_message(data, "No input for one Texture");
					return (false);
				}
				else if (!check_xpm_extension(data, array[1]))
					return (false);
				else
					data->texture_west = ft_strdup(array[1]);
			}
			else if (ft_strcmp(array[0], "EA") == 0)
			{
				if (size_array(array) != 2)
				{
					replace_error_message(data, "Texture in wrong format");
					return (false);
				}
				data->text_count_e++;
				if (!array[1])
				{
					replace_error_message(data, "No input for one Texture");
					return (false);
				}
				else if (!check_xpm_extension(data, array[1]))
					return (false);
				else
					data->texture_east = ft_strdup(array[1]);
			}
		}
		i++;
		free_2d_array(array);
	}
	if (!check_input_texture(data))
		return (false);
	return (true);
}
