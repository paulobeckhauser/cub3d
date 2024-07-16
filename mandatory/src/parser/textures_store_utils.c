/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_store_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:08:04 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:08:27 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	store_north_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "NO") == 0)
	{
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
	return (true);
}

bool	store_south_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "SO") == 0)
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
	return (true);
}

bool	store_west_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "WE") == 0)
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
	return (true);
}

bool	store_east_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "EA") == 0)
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
	return (true);
}
