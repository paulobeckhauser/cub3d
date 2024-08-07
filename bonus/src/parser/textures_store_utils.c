/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_store_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:08:04 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 20:08:19 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: store_north_texture_format
 * -------------------------------------
 * Stores the north wall texture specified in the configuration file.
 * 
 * data: A pointer to the game data structure.
 * array: An array of strings containing the texture identifier and path.
 * 
 * This function checks if the texture identifier matches "NO" for north wall,
 * validates the format, and stores the texture path in the game data structure.
 * It also handles memory allocation and error messaging.
 */
bool	store_north_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "NO") == 0)
	{
		if (size_array(array) != 2)
			return (replace_error_message(data, "Texture in wrong format"),
				false);
		data->text_count_n++;
		if (!array[1])
			return (replace_error_message(data, "No input for one Texture"),
				false);
		else if (!check_xpm_extension(data, array[1]))
			return (false);
		else
		{
			if (data->text_count_n != 0)
				free(data->texture_north);
			data->texture_north = ft_strdup(array[1]);
			if (!data->texture_north)
			{
				replace_error_message(data, "Memory allocation failed");
				return (free_variables_error(data), false);
			}
		}
	}
	return (true);
}

/* Function: store_south_texture_format
 * -------------------------------------
 * Stores the south wall texture specified in the configuration file.
 * 
 * data: A pointer to the game data structure.
 * array: An array of strings containing the texture identifier and path.
 * 
 * This function checks if the texture identifier matches "SO" for south wall,
 * validates the format, and stores the texture path in the game data structure.
 * It also handles memory allocation and error messaging.
 */
bool	store_south_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "SO") == 0)
	{
		if (size_array(array) != 2)
			return (replace_error_message(data, "Texture in wrong format"),
				false);
		data->text_count_s++;
		if (!array[1])
			return (replace_error_message(data, "No input for one Texture"),
				false);
		else if (!check_xpm_extension(data, array[1]))
			return (false);
		else
		{
			if (data->text_count_s != 0)
				free(data->texture_south);
			data->texture_south = ft_strdup(array[1]);
			if (!data->texture_south)
			{
				replace_error_message(data, "Memory allocation failed");
				free_variables_error(data);
				return (false);
			}
		}
	}
	return (true);
}

/* Function: store_west_texture_format
 * ------------------------------------
 * Stores the west wall texture specified in the configuration file.
 * 
 * data: A pointer to the game data structure.
 * array: An array of strings containing the texture identifier and path.
 * 
 * This function checks if the texture identifier matches "WE" for west wall,
 * validates the format, and stores the texture path in the game data structure.
 * It also handles memory allocation and error messaging.
 */
bool	store_west_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "WE") == 0)
	{
		if (size_array(array) != 2)
			return (replace_error_message(data, "Texture in wrong format"),
				false);
		data->text_count_w++;
		if (!array[1])
			return (replace_error_message(data, "No input for one Texture"),
				false);
		else if (!check_xpm_extension(data, array[1]))
			return (false);
		else
		{
			if (data->text_count_w != 0)
				free(data->texture_west);
			data->texture_west = ft_strdup(array[1]);
			if (!data->texture_west)
			{
				replace_error_message(data, "Memory allocation failed");
				free_variables_error(data);
				return (false);
			}
		}
	}
	return (true);
}

/* Function: store_east_texture_format
 * ------------------------------------
 * Stores the east wall texture specified in the configuration file.
 * 
 * data: A pointer to the game data structure.
 * array: An array of strings containing the texture identifier and path.
 * 
 * This function checks if the texture identifier matches "EA" for east wall,
 * validates the format, and stores the texture path in the game data structure.
 * It also handles memory allocation and error messaging.
 */
bool	store_east_texture_format(t_data *data, char **array)
{
	if (ft_strcmp(array[0], "EA") == 0)
	{
		if (size_array(array) != 2)
			return (replace_error_message(data, "Texture in wrong format"),
				false);
		data->text_count_e++;
		if (!array[1])
			return (replace_error_message(data, "No input for one Texture"),
				false);
		else if (!check_xpm_extension(data, array[1]))
			return (false);
		else
		{
			if (data->text_count_e != 0)
				free(data->texture_east);
			data->texture_east = ft_strdup(array[1]);
			if (!data->texture_east)
			{
				replace_error_message(data, "Memory allocation failed");
				free_variables_error(data);
				return (false);
			}
		}
	}
	return (true);
}
